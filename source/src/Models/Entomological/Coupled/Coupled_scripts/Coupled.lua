-- Coupled Model for Aedes aegypti population dynamic
-- Raquel Martins Lana, Tiago Garcia de Senna Carneiro, Cláudia Codeço, Tiago França Melo de Lima
-- Description:
-- Developed using TerraME 1.1.2
-- Geographical database developed in TerraView 4.2.0 and Mysql 5.5.25
-- Modelo Espaço Celular sem considerar vizinhança
-- Dados reais de temperatura e oviposição para Higienópolis
-- Modelo sem métrica de comparação espacial (sem calibração)

-------------------------------------------------------------------------------------- [[
RESULTS_PATH = BASE_PATH .. "/" .. RESULTS_DIR

logFile = io.open(RESULTS_PATH .. "/" .. RESULTS_FILE, "w+");
logFile:write("t\tamostraOvos\tovipostos\tpopOvos\tpopLarvas\tpopPupas\tpopAdultos\n")

dt = 1			-- one day
UPPER = dt*7	-- week
DELTA = dt/ODE	-- it can vary as needed

txTransOv = 1.0;	-- oviposition developmental rate: fixed

-- universal gas constant
R = 1.98
TabEntalpia = {
				{0.24,10798,100000,14184},
				{0.2088,26018,55990,304.6},
				{0.384,14931,-472379,148},
				{0.216,15725,1756481,447.2},
				{0.372,15725,1756481,447.2}
			}

if (POPULATION_TYPE == "Oviposition") then
	DEMAND_POPULATION = 0
else 
	if (POPULATION_TYPE == "Eggs") then
		DEMAND_POPULATION = 1
	else 
		if (POPULATION_TYPE == "Larvae") then
			DEMAND_POPULATION = 2
		else
			if (POPULATION_TYPE == "Pupae") then
				DEMAND_POPULATION = 3
			else
				if (POPULATION_TYPE == "Mosquitoes") then
					DEMAND_POPULATION = 4
				end
			end
		end
	end
end

DEMAND_POPULATION = string.byte(POPULATION_TYPE) - string.byte("0")
-------------------------------------------------------------------------------------- ]]

if(DEBUG_MODE) then print("-- DEBUG MODE"); end;
if(DEBUG_MODE) then print("start"); end;

----------------------------------------------------------------------------------------------------
-- Auxiliary Functions
----------------------------------------------------------------------------------------------------
function demandSpatializing( cs, demand )
	if(DEBUG_MODE) then print("spatializing demand function\t"); end;
	if(DEBUG_MODE) then print("\t demand: " .. demand); end;
--TODO: verificar a questão do uso de Trajectory
	local it = Trajectory{
		target = cs,
		filter = function( cell) return true; end,
		sort = function( cell1, cell2) return cell1.Intensidade > cell2.Intensidade; end
	}
--TODO: -- original passa it como parâmetro
	forEachCell( cs, 
	 	function(cell)
	 		cell.focus = 0;
	 	end
	)
	
	local allocated = 0;
    while (allocated < demand ) do
--TODO: -- original passa it como parâmetro
		forEachCell( cs, 
		 	function(cell)
				local quantity = cell.Intensidade * 63;
		 		if ( (quantity + allocated) > demand) then
		 			quantity = demand - allocated;
		 		end
		 		cell.focus = cell.focus + quantity;
		 		allocated = allocated + quantity;
		 		if( allocated >= demand) then return false; end
		 	end
		 )
		 if(DEBUG_MODE) then print("\t allocating: " .. allocated .. "\t" .. demand); end;
	end
	if(DEBUG_MODE) then print("\n spatializing done - allocated: " .. allocated .. "\n\n"); end;
	io.flush();
end


----------------------------------------------------------------------------------------------------
-- Load input file with model's configuration
----------------------------------------------------------------------------------------------------
-- 1) Configuration for model execution - PATH / LOG / DEBUG_MODE
-- 2) Input variables of model
-- 3) Database and obsever
--dofile("C:\\DengueME\\workspace\\coupled\\coupled_model_input.lua");


---------------------------------------------------------------------------------------------------
-- MODEL
----------------------------------------------------------------------------------------------------

demanda = {};
demanda.Ovos = 50;															-- VEM DO INPUT
demanda.Larvas = 0;
demanda.Pupas = 0;
demanda.Adultos = 0;

demanda.past = {};
demanda.past.Ovos = demanda.Ovos;
demanda.past.Larvas = demanda.Larvas;
demanda.past.Pupas = demanda.Pupas;
demanda.past.Adultos = demanda.Adultos;

function model(event)
	t = event:getTime()
	--for t = SIMULATION_TIME_START, SIMULATION_TIME_END, 1 do	
		
		-- Used to get the index of the table of temperatures
		if( t == 0) then idxTab = 0; else idxTab = math.ceil(t); end
	--	idxTab = 1 + math.mod( idxTab, #Temp);									-- lua 5.1 / TerraME 1.1.2
		idxTab = 1 + idxTab % #Temp;											-- lua 5.2 / TerraME 1.2.0
		
		temp = Temp[idxTab];
		temp = Temp[idxTab] + 273.15;
		
		-- Enzymatic kinetic equation proposed by Sharpe e DeMichele
		txTransO = TabEntalpia[1][1]*((temp/298)*math.exp((TabEntalpia[1][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[1][3]/R)*(1/TabEntalpia[1][4]-1/temp))));
		txTransL = TabEntalpia[2][1]*((temp/298)*math.exp((TabEntalpia[2][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[2][3]/R)*(1/TabEntalpia[2][4]-1/temp))));
		txTransP =  TabEntalpia[3][1]*((temp/298)*math.exp((TabEntalpia[3][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[3][3]/R)*(1/TabEntalpia[3][4]-1/temp))));
		
		if ( Temp[idxTab] < 4.85 or Temp[idxTab] > 33) then
			txTransO = 0;
			txTransL = 0;
			txTransP = 0;
		end
		
		---------------------------------------------------------------------------------------------------------
		-- ODE of populations
		---------------------------------------------------------------------------------------------------------
		oviposicao  = 0 ;
		auxTeste = 0;
		-- M ~ mortality rate
		-- M1 = eggs; M2 = larvae; M3 = pupae; M4 = mosquitoes
		-- developmental rates
		-- txTransOv = oviposition: fixed; txTransO = egg to larva; txTransL = larva to pupa; txTransP = pupa to adult
		demanda.Ovos, demanda.Larvas, demanda.Pupas, demanda.Adultos = d{
			{
				function(t, q)
					--oviposicao = txTransOv*cell.past.Adultos*(1- (q[1]/K));
					oviposicao = txTransOv*q[4]*(1- (q[1]/K));
					auxTeste = M1*q[1];
					return oviposicao - (txTransO*q[1]  + M1*q[1]) 
				end, 
				function(t, q) 
					return txTransO*q[1] - ( txTransL*q[2] + M2*q[2] )
				end,
				function(t, q)  
					return txTransL*q[2] - (txTransP*q[3] +  M3*q[3] ) 
				end,
				function(t, q)
					return txTransP*q[3] - (M4*q[4]) 
				end
			},
			{demanda.past.Ovos, demanda.past.Larvas, demanda.past.Pupas, demanda.past.Adultos}, 
			0, UPPER, DELTA 
	--		0, t, DELTA 
		}
		
		demanda.past.Ovos = demanda.Ovos;
		demanda.past.Larvas = demanda.Larvas;
		demanda.past.Pupas = demanda.Pupas;
		demanda.past.Adultos = demanda.Adultos;
		
		-- Report: save the simulation results
		if( t >= SIMULATION_TIME_START_LOG) and (t <= SIMULATION_TIME_END_LOG) then 
			logFile:write(t.."\t"..oviposicao.."\t"..demanda.Ovos.."\t"..demanda.Larvas.."\t"..demanda.Pupas.."\t"..demanda.Adultos.."\n" );
			local demand_population = 0;
			if (DEMAND_POPULATION == 0) then
				demand_population = oviposicao * DEMAND_SCALE;
			else 
				if (DEMAND_POPULATION == 1) then
					demand_population = demanda.Ovos * DEMAND_SCALE;
				else 
					if (DEMAND_POPULATION == 2) then
						demand_population = demanda.Larvas * DEMAND_SCALE;
					else
						if (DEMAND_POPULATION == 3) then
							demand_population = demanda.Pupas * DEMAND_SCALE;
						else
							if (DEMAND_POPULATION == 4) then
								demand_population = demanda.Adultos * DEMAND_SCALE;
							end;
						end;
					end;
				end;
			end;
			
			if(DEBUG_MODE) then 
				print(t.."\tEggs: "..demanda.Ovos.."\tLarvae: "..demanda.Larvas.."\tPupae: "..demanda.Pupas.."\tMosquitoes: "..demanda.Adultos); 
				print("\t\tspatializing population: ".. (#cs.cells)* demand_population); 
			else
				print(t.."\tEggs: "..demanda.Ovos.."\tLarvae: "..demanda.Larvas.."\tPupae: "..demanda.Pupas.."\tMosquitoes: "..demanda.Adultos); 
				print("\t\tspatializing population: ".. (#cs.cells)* demand_population); 
			end;
			
			demandSpatializing(cs, (#cs.cells)* demand_population )
			cs:notify()
		end;
	end

-- ALTERADO AQUI - CRIADO TIMER COM EVENTO
simulation_timer = Timer {
	Event{ 
		--time = SIMULATION_TIME_START, period = 1; priority = -1,
		action = function(event)
			print("Time:", event:getTime()) io.flush()
			model(event);
			simulation_timer:notify();
		end
	}
}
-- ALTERADO AQUI 
obsText = Observer{ subject = simulation_timer, type = "textscreen"}
-- ALTERADO AQUI 
simulation_timer:execute(10000)

if(DEBUG_MODE) then 
	print("VALORES MAXIMOS\n\tOviposicao:" .. maximo_oviposicao .. " - Ovos:" .. maximo_ovos .. " - Larvas:" .. maximo_larvas .. "- Pupas:" .. maximo_pupas .. " - Adultos:" .. maximo_adultos);
end;

-- close log file
logFileGlobalOutput:close();
logFileIndividualOutput:close();
--logFileError:close();
--debugFile:close();

-- close log file
logFile:close();
print("READY");
io.flush();

os.exit();
