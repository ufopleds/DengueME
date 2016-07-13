--% Main = programa principal
--% DenDyn = Dinamica da Dengue
--**************************************
-- FASE DE PROGRAMACAO:
-- COM probabilidades de contaminacao
-- COM iip (percentual de células com mosquito, dentre as celulas com humanos)
-- COM percentual de células ocupadas por humanos
-- COM frequência de picadas de mosquitos
-- COM número variável de mosquitos por celula
-- COM visualização (png por enquanto)
-- COM renovação de mosquitos
-- COM renovação de humanos
-- COM revisão de trajectory (utilizando synchronize())
-- COM períodos FIXOS de incubacao (SEIR e SEI)
-- COM mobilidade de humanos
-- COM mobilidade de mosquitos
-- 		sem numero variavel de humanos por celula 
-- 		sem vetor de probabilidades de raio de voo de mosquitos (ou funcao de distancia)
-- 		apenas um sorotipo
-- 		sem sazonalidade de mosquitos
--**************************************

dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/init.lua");
---------------------------------------------------------------------------

-- procedure to ensure the pseudorandom numbers are not fixed 
math.randomseed(os.time());
math.random();


--%--------- Inicialization of Variables and Parameters--------------------
-----------------------------------------------------------------------------
-- cell.Hstate = "Empty" means "the cell is an empty lot"	
-- cell.Hstate = "SuscNoInfecs" means "there is at least one susceptible and no infecteds"
-- cell.Hstate = "Infecs" means "there are infected humans in the cell"
-- cell.Hstate = "AllRecovereds" means "all humans in the cell are recovered"

classesHum = {
	-- Empty = "Empty Cell",
	-- SuscNoInfecs = "No Infected Humans",
	-- Infecs = "At least 1 infected Human",
	-- AllRecovereds = "All Humans Recovered"
	Empty = 0,
	SuscNoInfecs = 1,
	Infecs = 2,
	AllRecovereds = 3
}

----------------------------------------------------------------------------
---------------- CREATION OF A CELLULAR SPACE-------------------------------

--if(VIRTUAL_CS)then
--	-- Creating the cellular space at the memory
--	cellSpace = CellularSpace{	xdim = XDIMENSION, ydim = YDIMENSION }
--else
--	if(USE_POPULATION_DATA)then
--		cellSpace = CellularSpace{
--			dbtype = DATABASE_TYPE,
--			host = DATABASE_HOST,
--			database = DATABASE_NAME,
--			user = USER,
--			password = PASSWORD,
--			theme = THEME_NAME,
--			select = {POPULATION_ATTRIBUTE}
--		}
--	else
--		cellSpace = CellularSpace{
--			dbtype = DATABASE_TYPE,
--			host = DATABASE_HOST,
--			database = DATABASE_NAME,
--			user = USER,
--			password = PASSWORD,
--			theme = THEME_NAME
--		}
--	end
--end

cellSpace = cs
PATH_RESULTS = RESULTS_PATH
if(POPULATION_ATTRIBUTE == nil)then
	POPULATION_ATTRIBUTE = "population"
end
if(POPULATION_PERCENTAGE == nil and USE_POPULATION_DATA)then
	POPULATION_PERCENTAGE = 1;
end

-----------------------------------------------------------------------------
-- Check if the directory exists, if it does't, it is created
-- Check is made through the os.rename() function because Lua does not have
-- any function to do that.
if( os.rename(PATH_RESULTS, PATH_RESULTS) == nil )then
	os.execute("mkdir "..PATH_RESULTS);
end


----------------- TEMPLATE OF FEMALE MOSQUITO AGENT -----------------------------
fmosqAgent = Agent{
    state = "S",
    -- state can be: S (susceptible), E (infected not infectious (exposed)) or 
	--               I (infected infectious)
	IncPer = 9,
	-- IncPer = period of extrinsic incubation (now it is constant for every vector)
    timeOfInfec = 0,
	-- timeOfInfec = counting time after biting a infectious human and counting time 
	--               when in infectious state. To facilitate the program, this time will 
	--               be reseted at the moment the vector changes from E state to I state
	init = function(self)
--        self.age = 0;
    end,
    execute = function(self)
        local fmosqCell = self:getCell("fmosquitoes");
        -- To ensure the computational efficiency of the model:
        -- do the dynamics of infection only if there are mosquitoes or humans to be infected
        if (fmosqCell.past.trajec == 1) then --or (self.state == "I") then
        	-- Calculating the number of bites of the mosquito in that day
			local BiteNumber = RoundProb(BITE_FREQUENCY);
			if BiteNumber > 0 then
				-- Drafting one cell of the ring with probability [PROB_DRAFT_CENTRAL_CELL,1-PROB_DRAFT_CENTRAL_CELL]
    			if (math.random() <= PROB_DRAFT_CENTRAL_CELL) then 
    				-- targetCell is the same cell
    				targetCell = fmosqCell;    									     												
    			else
    				---------------------------------------------------------------------
    				-- MOVING PROCEDURE:
    				-- Retrieving the female mosquito neighborhood
    				--local fneighborhood = fmosqCell:getNeighborhood();
    				-- Drafting one cell in the female mosquito neighborhood
    				local neighborhood = fmosqCell:getNeighborhood();
    				if(neighborhood:size() > 0)then
    					targetCell = neighborhood:sample();
    				else
    					targetCell = fmosqCell;
    				end
    				--targetCell = fneighborhood:sample();
    				-- Moving the female mosquito to the new cell 	
    				self:move(targetCell,"fmosquitoes");	
    				-- Updating the NfMosqs attribute    				
    				targetCell.NfMosqs = targetCell.NfMosqs + 1;
    				fmosqCell.NfMosqs = fmosqCell.NfMosqs - 1;
    				-- Updating countings in the old cell 
	    			-- (in the new cell, the update is made in case the mosquito survive (below))
	    			if self.state == I then
	    				fmosqCell.NInfecFM = fmosqCell.NInfecFM - 1; 
	    			elseif self.state == E then
	    				fmosqCell.NExposFM = fmosqCell.NExposFM - 1; 
	    			end
	    			-- Marking the cell to Update Module (cell.FMstate)
	    			targetCell.trajec = 1;
	    			--------------------------------------------------------------------
	    			-- Renaming the target cell	    			
	    			fmosqCell = targetCell;    
	    							
    			end

    			for bites = 1,BiteNumber,1 do									
					-- Calculating the probability of having a visitor in the cell (based on my dissertation)
    				-- if the target cell is a public location
    				if (targetCell.use == "publoc") then
    					ProbVis = PERCENTAGE_HUMANS_PUBLIC_LOCATIONS * HUMAN_MOBILITY_PERCENTAGE;
    				else
    					ProbVis = (1-PERCENTAGE_HUMANS_PUBLIC_LOCATIONS)*HUMAN_MOBILITY_PERCENTAGE;    					
    				end
    				 		
    				-- Calculating the chance of biting a human visitor (it depends of the number 
    				-- of people in the target cell)
    				ProbVis = ProbVis * (1/(1+targetCell[POPULATION_ATTRIBUTE]));
    				    								
    				-- Drafting one human of the Human Society in the targetCell or a visitor: 								
    				-- if the target human isn't a visitor
    				if (math.random() <= (1-ProbVis)) then
    					--print(targetCell.humans:size())
    					--print(targetCell:getAgents("humans"))
    					targetHuman = targetCell.humans:sample(); 
    					--print("targetHuman.state = ",targetHuman.state) 
					-- if the target human is a visitor one
    				else        								
    					-- Draft a ramdom cell with humans inside
    					repeat
							visitorCell = cellSpace:sample();
						until (visitorCell.Hstate ~= "Empty")
						-- Draft one human of the Human Society in the visitor cell 	
						targetHuman = visitorCell.humans:sample(); 
						--print(targetHuman.state)
						-- if the visitor is a symptomatic one and infectious at the same time
						if (targetHuman.state == "I") and (math.random() <= (1-PERCENTAGE_ASSYMPTOMATIC_INFECTED_HUM)) then
							-- discard the visitor, because he would not leave home if sick
							targetHuman = targetCell.humans:sample();  
						else	
							targetCell = visitorCell;							
						end
    				end
    								
    				-- Infection rules
    				--print("mosquito.state = ",self.state)
    				if (self.state == "I") and (targetHuman.state == "S") and (math.random() <= PROB_INFEC_FROM_VEC_TO_HUM) then
    					--print("entrei aqui")
    					-- Infecting the target human (becoming an exposed one)
						targetHuman.state = "E";
						targetCell.NExposH = targetCell.NExposH + 1;
						-- Updating the counter of new infected humans
						NDNHumE = NDNHumE + 1;
						-- Marking the cells to be accessed in the next dynamical trajectory 
						targetCell.trajec = 1;
						forEachNeighbor(
							targetCell,
							function(targetCell,neighbor)
								neighbor.trajec = 1;
							end
						)
					end
    				if (self.state == "S") and (targetHuman.state == "I") and (math.random() <= PROB_INFEC_FROM_HUM_TO_VEC) then
    					-- Infecting the female mosquito (becoming an exposed one)
    					self.state = "E";
    					fmosqCell.NExposFM = fmosqCell.NExposFM + 1; 
    					-- Updating the counter of new infected female mosquitoes
    					NDNfMosqE = NDNfMosqE + 1;  
    					-- Marking the cells to be accessed in the next dynamical trajectory 
						--fmosqCell.trajec = 1;  -- acho que não precisa, pois a célula juá está marcada pelo humano infectado 					
    				end
    			end
    		end
       	end 

-- MORTE - COMECA AQUI
    	    	
    	-- Updating the female mosquito attributes and the counters in mosquitoes society
    	-- (Due to age update, it can not be included in trajec attribute)
	   	-- If the female mosquito survives 
        if (math.random() <= FEMALE_MOSQ_LIFE_PROBABILITY) then
--        	self.age = self.age + 1;  
        	if self.state == "I" then 
				-- This female mosquito remains in the "I" state
				--fmosqCell.NInfecFM = fmosqCell.NInfecFM + 1;
				-- Updating the cell states to Observer
				fmosqCell.FMstate = "Infecs";
				-- Marking the cells to be accessed in the next dynamical trajectory 
				fmosqCell.trajec = 1;
			end
			if (self.state == "E") then
				if (self.timeOfInfec < self.IncPer) then	
					-- This female mosquito remains in the "I" state
					self.timeOfInfec = self.timeOfInfec + 1;	
					--fmosqCell.NExposFM = fmosqCell.NExposFM + 1;				
				else
					if (self.timeOfInfec == self.IncPer) then
					-- This female mosquito changes to "I" state
						self.state = "I";
						self.timeOfInfec = 0;
						fmosqCell.NInfecFM = fmosqCell.NInfecFM + 1;
						fmosqCell.NExposFM = fmosqCell.NExposFM - 1;	
						-- Marking the cells to be accessed in the next dynamical trajectory 
						fmosqCell.trajec = 1;	
					end
				end	
				-- Marking the cells to be accessed in the next dynamical trajectory 
				--fmosqCell.trajec = 1;				
				-- Updating the cell states to Observer
				fmosqCell.FMstate = "Infecs";		
			end	
		-- If the female mosquito doesn't survive 
		else
			if (self.state == "E") then
				fmosqCell.NExposFM = fmosqCell.NExposFM - 1;	
				NDeadFMosqEII = NDeadFMosqEII + 1;				
			end
			if (self.state == "I") then 
				fmosqCell.NInfecFM = fmosqCell.NInfecFM - 1;
				NDeadFMosqEII = NDeadFMosqEII + 1;
			end
			-- Female mosquito is born again (reset the attributes)
--			self.age = 0; --(isso é novo!)
			self.state = "S";
			self.IncPer = 9;
			self.timeOfInfec = 0;				
		end
	end
	
-- MORTE - TERMINA AQUI
}        
        
-----------------------------------------------------------------------------
----------------- TEMPLATE OF HUMAN AGENT -----------------------------------
humanAgent = Agent{
	state = "S", 
	-- state can be: S (susceptible), E (infected not infectious (exposed)), 
	--               I (infected infectious) or R (recovered)
	IncPer = 5, 
	-- IncPer = period of intrinsic incubation (now it is constant for every human)
	tToRecover = 5, 
	-- tToRecover = viraemia period (now it is constant for every human)
	timeOfInfec = 0,
	-- timeOfInfec = counting time after the vector bite and counting time when in 
	--               infectious state. To facilitate the program, this time will 
	--               be reseted at the moment the human changes from E state to I state    
    execute = function(self)
        local humanCell = self:getCell("humans");
        -- Updating the time of infection in humans, the counters, the state to recover
		if (humanCell.past.trajec == 1) then
			if (self.state == "I") then
				if (self.timeOfInfec < self.tToRecover) then
					-- This human remains in the "I" state
					self.timeOfInfec = self.timeOfInfec + 1; 
					--humanCell.NInfecH = humanCell.NInfecH + 1;
					-- The cells to be accessed in the next dynamical trajectory will be marked 
					-- in the Update Cell Module								
				else
					if (self.timeOfInfec == self.tToRecover) then
						-- This human changes to "R" state
						self.state = "R";
						humanCell.NInfecH = humanCell.NInfecH - 1;
						humanCell.NRecoverH = humanCell.NRecoverH + 1;
						NDNHumR = NDNHumR + 1;
					end
				end			
			end
			if (self.state == "E") then
				if (self.timeOfInfec < self.IncPer) then	
					-- This human remains in the "E" state
					self.timeOfInfec = self.timeOfInfec + 1;
					--humanCell.NExposH = humanCell.NExposH + 1;									
				else
					if (self.timeOfInfec == self.IncPer) then
						-- This human changes to "I" state
						self.state = "I";
						self.timeOfInfec = 0;
						humanCell.NExposH = humanCell.NExposH - 1;	
						humanCell.NInfecH = humanCell.NInfecH + 1;					
					end
				end	
				-- The cells to be accessed in the next dynamical trajectory will be marked 
				-- in the Update Cell Module									
			end
		end				
	end
}	
-----------------------------------------------------------------------------



------- CREATING SOCIETIES --------------------------------------------------
-- Creating a Female Mosquito Society without agents ------------------------
	FMosqSoc = Society {
    		   instance = fmosqAgent
	}
	
-- CREATING A HUMAN SOCIETY WITHOUT AGENTS ----------------------------------
	HumanSoc = Society {
    		   instance = humanAgent
	}
-----------------------------------------------------------------------------	


------- CONECTING CELL SPACE WITH AGENTS IN ONE ENVIRONMENT -----------------
EnvH = Environment {
    cellSpace,
    HumanSoc    
}

EnvH:createPlacement{strategy = "void", name = "humans"}

EnvFM = Environment {
    cellSpace,
    FMosqSoc    
}

EnvFM:createPlacement{strategy = "void", name = "fmosquitoes"}

-----------------------------------------------------------------------------

------- LOADING THE CELLULAR SPACE WITH HUMANS AND FEMALES MOSQUITOES -------
------- AND CREATING CELL ATTRIBUTES
cellSpace, HumanSoc, FMosqSoc, NTotHum, NTotFMosq, MaxHum, MaxFMosqByHuman =
			LoadCellSpaceAtt3_2(cellSpace,HumanSoc,PERCENTAGE_CELLS_HUMANS,FMosqSoc,PERCENTAGE_CELLS_FEM_MOSQ,MAXIMUM_PROP_VEC_HUMAN,
								PERCENTAGE_PUBLIC_LOCATIONS,SAVE_IMAGES,classesHum, VIRTUAL_CS, USE_POPULATION_DATA, POPULATION_PERCENTAGE);			

print("-------------------------------------------------");
print("Total Number of Humans = "..NTotHum)
print("Total Number of Mosquitoes = "..NTotFMosq)
print("-------------------------------------------------");

-- Daily number of renovated humans
DailyHRenewal = (ANNUAL_HUMAN_RENEWAL*NTotHum)/360; -- the decimal part of this number will become a daily probability 
										   			-- to renewal one more human  
-----------------------------------------------------------------------------

--------- CREATION OF NEIGHBORHOODS (only the Moore-modified type, because of the mosquitoes range)
cellSpace:createNeighborhood{strategy = "moore", self = false} -- Moore neighborhood
-- In the new version of TerraME, in default, the central cell does nor belong to the neighborhood 
-- (it will help to draft the ring of mosquitoes' vicinity, like [70,30], [90,10], and so on)
forEachCell(cellSpace,
	function(cell)
		-- Erasing the cells in the neighborhoods that there aren't humans inside
		forEachNeighbor(
			cell,
			function(cell,neighbor)
				local neighborhood = cell:getNeighborhood();
				-- If there aren't humans in the neighbor cell, the female mosquitoes 
				-- don't go there to bite
				if neighbor.Hstate == "Empty" and neighborhood:size() > 1 then
					neighborhood:eraseNeighbor(neighbor); 					                                      
				end	
			end
		)							
	end
)
---------------------------------------------------------------------------------------


----------- INITIAL CONDITION: INFECTING A HUMAN ON THE NETWORK -----------------------
-- the typeCond determines the type of intial condition
typeCond = "RandomlyDist" -- random distributed humans will be infected and recovered as initial condition
cellSpace, NDHumI, NDHumR, NDNHumE, NDfMosqI, NDNfMosqE = InitCond(cellSpace,typeCond,INITIAL_NUMBER_INFECTED,INITIAL_NUMBER_RECOVERED,classesHum); -- this is some kind of execute for the 1st step
iter = 0;
ProbVis = 0;
NDNHumR = 0; -- Daily number of new recovered humans
SomaFMS = NTotFMosq;
SomaHS = NTotHum - 1;
---------------------------------------------------------------------------------------
-- Open the file to save some data generated in the iterations
if ( LOG ) then
	fileResultados = io.open(PATH_RESULTS.."/LogEpidemiologicalModel.csv", "w+");

	fileResultados:write("Day;Numero diario de humanos infectados;Numero diario de novos humanos expostos;"
						 .."Numero diario de humanos recuperados;Numero diario de novos humanos recuperados;"
						 .."Numero total de humanos;Numero diario de mosquitos infectados;"
						 .."Numero diario de novos mosquitos expostos;Numero diario de vetores;"
						 .."Numero diario de mosquitos susceptiveis;Numero diario de humanos susceptiveis\n");

	fileResultados:write(iter..";"..NDHumI..";"..NDNHumE..";"..NDHumR..";"..NDNHumR..";"..NTotHum..";"..
						 NDfMosqI..";"..NDNfMosqE..";"..NTotFMosq..";"..SomaFMS..";"..SomaHS.."\n");
end
----------------------------------------------------------------

if (SAVE_IMAGES or OBSERVER_MAP) then
	csLegH = Legend{
		-- type = "string",
		type = "number",
		grouping = "uniquevalue",
		colorBar = {
			-- {value = "Empty Cell", color = "black"},
			-- {value = "No Infected Humans", color = "blue"},
			-- {value = "At least 1 infected Human", color = "red"},
			-- {value = "All Humans Recovered", color = "green"}
			{value = 0, color = "black"},
			{value = 1, color = "blue"},
			{value = 2, color = "red"},
			{value = 3, color = "green"}
		}
	}
end
	
if ( SAVE_IMAGES ) then
	obsCsImgH = Observer{
		subject = cellSpace,
		type = "image",
		attributes = {"humans_condition"},
		prefix = "HumEpi_",
		path = PATH_RESULTS,
		legends = {csLegH}
	}
	cellSpace:notify();
end

if ( OBSERVER_MAP ) then
	obsCsMapH = Observer{
		subject = cellSpace,
		type = "map",
		attributes = {"humans_condition"},
		legends = {csLegH}
	}
	
	cellSpace:notify()
end
	
-- DYNAMICS OF INFECTION ---------------------------------------
-- Proportion of cells with infected humans			  
PropCellIH = 0;

-- for TotalDias iterations
for iter = 1,TOTAL_NUMBER_DAYS,1 do

	print("Day "..iter)
	
	--print("t = "..iter)
	-- Resetting the counter variables
	NDHumIE = 0; -- Daily number of infected EXPOSED humans
	NDHumII = 0; -- Daily number of infected infectious humans 
	NDHumI = 0; -- Daily number of total infected humans
	NDNHumE = 0; -- Daily number of new infected humans
	NDNHumR = 0; -- Daily number of new recovered humans
	NDNfMosqE = 0; -- Daily number of new infected female mosquitoes
	NCellIH = 0; -- Number of cells with infected humans
	NDeadFMosqEII = 0; -- Number of dead infected female mosquitoes
	MaxFMosqByHuman = 0; -- Maximum proportion fmosquitoes:human by cell
	SomaHS = 0; -- Total number of susceptible humans
	SomaFMS = 0;

    -- Saving the "past" of the attribute "trajec" for all cells of the cell space
	cellSpace:synchronize(trajec); 
	-- Reseting the trajec attribute for each cell
	forEachCell(
		cellSpace,
		function(cell)	
			cell.trajec = 0;	
		end
	)
		
    ----------------------------------------------------------------------------
	-- Dymanics of Transmission - Rules MODULE 
	FMosqSoc:execute();
	HumanSoc:execute();
		
	
	-- Update MODULE -----------------------------------------------------------
	-- Updating the daily number of infected female mosquitoes
	NDfMosqI = NDfMosqI + NDNfMosqE - NDeadFMosqEII;
	-- Updating the daily number of recovered humans
	NDHumR = NDHumR + NDNHumR;
	-- Human Renewal MODULE
	cellSpace, NDHumR = DailyNHumRenewal(cellSpace,DailyHRenewal,NDHumR);	
	forEachCell(
		cellSpace,
		function(cell)			
			-- Calculating the maximum proportion fmosquitoes:humans with relation of all cells
			if (cell.Hstate ~= "Empty") then
	    		if MaxFMosqByHuman < (cell.NfMosqs/cell[POPULATION_ATTRIBUTE]) then
	    			MaxFMosqByHuman = RoundNearExt((cell.NfMosqs/cell[POPULATION_ATTRIBUTE]),2);
	    		end	 
	    	end	
			-- Updating the daily number of infected female mosquitoes
			--NDfMosqI = NDfMosqI + cell.NInfecFM;
			-- If the cell belongs to the dynamical trajectory (the olders and the new ones)
			if (cell.past.trajec == 1) or (cell.trajec == 1) then 
				-- Function to update the cell atributes related with humans
				cell = UpdateCell2_0(cell,classesHum);	
				-- Updating the counters:
				-- If there are infected humans in the cell
				if (cell.Hstate == "Infecs") then
					-- Update the daily number of infected humans
					NDHumIE = NDHumIE + cell.NExposH;
					NDHumII = NDHumII + cell.NInfecH;
					-- Number of cells with infected humans
					NCellIH = NCellIH + 1;					
				end							
			end
		end
	)
	-- Updating the daily number of all kind of infected humans
	NDHumI = NDHumIE + NDHumII; 
	--print("NDHumI = "..NDHumI)
	-- Updating the daily number of infected humans
	--NDHumI = NDHumI + NDNHumE;
	-- Proportion of cells with infected humans
	
	-- Raian: Alterei isto para pegar a dimensao do CS, ao inves de pegar a variavel csDim
	PropCellIH = NCellIH/(#cellSpace.cells * PERCENTAGE_CELLS_HUMANS);
	-- Raian: FIM
	
	----------------------------------------------------------------------------
	forEachCell(
		cellSpace,
		function(cell)
			if (cell.Hstate ~= "Empty") then
				forEachAgent(	
					cell.humans,
					function(agentH)
						if (agentH.state == "S") then 
							SomaHS = SomaHS + 1
						end						
					end
				)
				forEachAgent(	
					cell.fmosquitoes,
					function(agentFM)
						if not((agentFM.state == "I") or (agentFM.state == "E")) then 
							SomaFMS = SomaFMS + 1;							
						end						
					end
				)
			end	
		end		
	)	
	
	----------------------------------------------------------------------------
	-- Updating Log File
	if(LOG == true)then
		fileResultados:write(iter..";"..NDHumI..";"..NDNHumE..";"..NDHumR..";"..NDNHumR..";"..NTotHum..";"..
							 NDfMosqI..";"..NDNfMosqE..";"..NTotFMosq..";"..SomaFMS..";"..SomaHS.."\n");
	end
	
	if ( SAVE_IMAGES ) then 
		if (math.fmod(iter,FREQUENCY_SAVE_IMAGES) == 0) then
			cellSpace:notify();
		end
	end
	if( OBSERVER_MAP ) then
		cellSpace:notify();
	end
end
----------------------------------------------------------------

if ( LOG ) then
	fileResultados:close();
end
print("-------------------------------------------------");
print("READY!")
os.exit()
