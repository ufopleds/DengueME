
-- This function loads the cell space attributes and create humans agents and female mosquitoes agents 
-- Raian: Alterar o nome da função 
function LoadCellSpaceAtt3_2(cellSpace,HumanSoc,HumPerc,FMosqSoc,MosqPerc,MaxVecProp,PubLocCellPerc,Vis,classesHum, VIRTUAL_CS, USE_POPULATION_DATA, POPULATION_PERCENTAGE)
         
	NTotHum = 0; 
	NTotFMosq = 0;
	MaxHum = 0;
	--MaxFMosq = 0;
	MaxFMosqByHuman = 0;
	-- For each cell of the cellular space, apply the function defined inside the command 
	-- 'forEachCell'
	forEachCell(
		cellSpace,
		function(cell)
			-- Creating an attribute to mark the cells that need to apply the transmission dynamics 
			-- (some kind of trajectory tool)
	    	cell.trajec = 0;
			-- If there are humans in the cell, do
			if (math.random() <= HumPerc or USE_POPULATION_DATA) then	-- OBS: Here we can choose other rule to determine 
												-- if there are humans in the cell. For example,
												-- based on geographical barriers on captured images   
	    		-- Creating cell attributes (to use the observer/visualization tool)
	    		--if (Vis == true) then
	    			cell.Hstate = "SuscNoInfecs";
	    			cell.humans_condition = classesHum[cell.Hstate];
	    			-- cell.Hstate = "Empty" means "the cell is an empty lot"	
	    			-- cell.Hstate = "SuscNoInfecs" means "there is at least one susceptible and no infecteds"
	    			-- cell.Hstate = "Infecs" means "there are infected humans in the cell"
	    			-- cell.Hstate = "AllRecovereds" means "all humans in the cell are recovered"
	    		--end
	    			
	    		-- Attribute specifying the use of the cell (to human mobility based on attraction points)
	    		if (math.random() <= (1-PubLocCellPerc)) then
	    			-- the cell use is domestic
	    			cell.use = "domestic";
	    		else
	    			-- the cell use is public location
	    			cell.use = "publoc";
	    		end
	    		
	    		-- Atribute that give the number of humans agents in the cell
	    		-- RAIAN: Alterei para acertar a quantidade de humanos por celula quando se utiliza o BD.
	    		if(VIRTUAL_CS or (not USE_POPULATION_DATA))then
		    		cell[POPULATION_ATTRIBUTE] = HUMANS_BY_CELL;
		    	else
		    		cell[POPULATION_ATTRIBUTE] = cell[POPULATION_ATTRIBUTE] * POPULATION_PERCENTAGE;
		    	end
		    	--RAIAN: FIM 
		    	
	    		NTotHum = NTotHum + cell[POPULATION_ATTRIBUTE];
	    		-- Calculating the maximum number of humans with relation of all cells
	    		if (MaxHum < cell[POPULATION_ATTRIBUTE]) then
	    			MaxHum = cell[POPULATION_ATTRIBUTE];
	    		end	    
	    		
	    		-- Putting HUMANS_BY_CELL humans into the current cell
				for i = 1, cell[POPULATION_ATTRIBUTE], 1 do
					-- creating a new human agent
		    		agentH = HumanSoc:add();
		    		-- placing the new human agent in the current cell and specifying the "class" (environment) it belongs
					agentH:enter(cell, "humans");														
		    	end	
		    			    	
	    		-- if there are mosquitoes in the cell, do
	    		if (math.random() <= MosqPerc) then
	    			-- Creating cell attributes (to use the observer/visualization tool)
	    			--if (Vis == true) then
	    				cell.FMstate = "SuscNoInfecs";
	    				-- cell.FMstate = "NoFMosqs" means "there aren't female mosquitoes in the cell"	
	    				-- cell.FMstate = "SuscNoInfecs" means "every female mosquito in the cell is susceptible"
	    				-- cell.FMstate = "Infecs" means "there are infected female mosquitoes in the cell"
	    			--end
	    				    			
	    			-- Atribute that give the number of vectors agents in the cell
	    			cell.NfMosqs = NumFMosqCell(MaxVecProp,cell[POPULATION_ATTRIBUTE]); -- RAIAN: Para alterar a condicao inicial, alterar aqui (Olhar codigo que fiz com Tiago)
	    			--print("cell.NfMosqs = ",cell.NfMosqs)
	    			NTotFMosq = NTotFMosq + cell.NfMosqs;
	    			-- Calculating the maximum proportion fmosquitoes:humans with relation of all cells
	    			if MaxFMosqByHuman < (cell.NfMosqs/cell[POPULATION_ATTRIBUTE]) then
	    				MaxFMosqByHuman = RoundNearExt((cell.NfMosqs/cell[POPULATION_ATTRIBUTE]),2);
	    			end	   
	    						
	    			-- Putting NumFMosqCell female mosquitoes in the current cell
					for i = 1, cell.NfMosqs, 1 do
						-- creating a female mosquito agent
						agentFM = FMosqSoc:add();
						-- placing the new female mosquito agent in the current cell and specifying the "class" (environment) it belongs
						agentFM:enter(cell,"fmosquitoes");	
						--print(cell.fmosquitoes:size())
						--error("aaa")											    			
		    		end	
		    		
	    		-- if there aren't mosquitoes in the cell, do
	    		else 	
	    			-- Creating cell attributes (to use the observer/visualization tool)
	    			--if (Vis == true) then
	    				cell.FMstate = "NoFMosqs"; -- to indicate that there aren't vectors in the cell	
	    			--end
	    			cell.NfMosqs = 0;
	    		end
	    		    		    				    							
			-- If there aren't humans in the cell, do				
			else
				cell.use = "emptyLot";
				-- Cell attribute to use the observer/visualization tool
				-- Creating cell attributes (to use the observer/visualization tool)
	    		--if (Vis == true) then
					cell.Hstate = "Empty" -- The cell is an empty lot	~
					cell.humans_condition = classesHum[cell.Hstate];
					cell.FMstate = "NoFMosqs"; -- to indicate that there aren't vectors in the cell	
				--end	
	    		-- Atribute that give the number of agents in the cell
				cell[POPULATION_ATTRIBUTE] = 0;
	    		cell.NfMosqs = 0;
			end
			-- Cell attributes to use to the counting and to the observer/visualization tool
			cell.NExposH = 0;   -- number of exposed humans (infected but not infectious) in the cell
	    	cell.NInfecH = 0;   -- number of infected infectious humans in the cell
	    	cell.NRecoverH = 0; -- number of recovered humans in the cell	
			cell.NExposFM = 0;  -- number of exposed female mosquitoes (infected but not infectious) in the cell
	    	cell.NInfecFM = 0;  -- number of infected female mosquitoes in the cell
	    	
	    	--print(cell.humans:size())
	    	--print(cell.fmosquitoes:size())
	    	--if cell.Hstate == "Empty" then
	    	--	print("ops!")
	    	--end	
				    	    	
		end
	)
	return cellSpace, HumanSoc, FMosqSoc, NTotHum, NTotFMosq, MaxHum, MaxFMosqByHuman  --MaxFMosq        
end	




-- Function to calculate the number of vectors in a specific cell (always > 0)
function NumFMosqCell(MaxVecProp,NHCell)
	local VecProp = 1 - math.random(); -- math.random generates numbers in the range [0,1)
	                                   -- 1 - math.random generates numbers in the range (0,1]
	-- Convert the number in (0,1] interval to (0,MaxVecProp] interval
	VecProp = MaxVecProp * VecProp;
	-- Calculating the number (real) of vectors in the cell
	NVecCell = VecProp * NHCell;
	-- Applying the probabilistic rounding to NVecCell
	NVecCell = RoundProb(NVecCell);
	-- But this number cannot be 0
	if NVecCell == 0 then
		NVecCell = 1;
	end
	return NVecCell
end

