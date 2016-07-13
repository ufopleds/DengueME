-- Coupled Model for Aedes aegypti population dynamic
-- Raquel Martins Lana, Tiago Garcia de Senna Carneiro, Cláudia Codeço, Tiago França Melo de Lima
-- Description:
-- Developed using TerraME 1.1.2
-- Geographical database developed in TerraView 4.2.0 and Mysql 5.5.25
-- Modelo Espaço Celular sem considerar vizinhança
-- Dados reais de temperatura e oviposição
-- Modelo sem métrica de comparação espacial (sem calibração)


-------------------------------------------------------------------------------------- [[
RESULTS_PATH = BASE_PATH .. "/" .. RESULTS_DIR

function effectiveness_rate(Tn, Ta, k, Zg)
	if (Tn <= Ta) then
		return k * ( 1 - ((Tn*Tn) / (Ta*Ta)) ) * ( 1 - Zg );
	else
		return 0;
	end;
end;

logFileGlobalOutput = io.open(RESULTS_PATH .. "/" .. GLOBAL_RESULTS_FILE, "w+");
logFileIndividualOutput = io.open(RESULTS_PATH .. "/" .. INDIVIDUAL_RESULTS_FILE, "w+");
--logFile:write("t\tCelula\tCapacidadeDeSuporte\tOviposicaoSemanal\tPopulacaoOvos\tPopulacaoLarva\tPopulacaoPulpa\tPopulacaoAdulto\tFocus\n");
--logFileError = io.open(RESULTS_PATH.."\\UltimaVersao1Erro.csv", "w+");
--logFileError:write("t\tOviposicaoSimulada\tOviposicaoReal\n");
--debugFile = io.open(RESULTS_PATH.."\\DEBUG.csv", "w+");

log_globalOutput = {}
log_globalOutput['temperature'] = GLOBAL_TEMP
log_globalOutput['oviposition'] = GLOBAL_OVIP
log_globalOutput['popEggs'] = GLOBAL_EGGS
log_globalOutput['popLarvae'] = GLOBAL_LARVAE
log_globalOutput['popPupae'] = GLOBAL_PUPAE
log_globalOutput['popMosquitoe'] = GLOBAL_MOSQUITOES
log_globalOutput['devRateEggLarva'] = GLOBAL_EGGLARVA
log_globalOutput['devRateLarvaPupa'] = GLOBAL_LARVAPUPA
log_globalOutput['devRatePupaAdult'] = GLOBAL_PUPAMOSQUITO

logGR_header = "t" .. (log_globalOutput['temperature'] and ("\ttemperature") or "") .. 
				(log_globalOutput['oviposition'] and ("\tovipostos") or "") .. 
				(log_globalOutput['popEggs'] and ("\tpopOvos(total)") or "") .. 
				(log_globalOutput['popLarvae'] and ("\tpopLarvas(total)") or "") .. 
				(log_globalOutput['popPupae'] and ("\tpopPupas(total)") or "") .. 
				(log_globalOutput['popMosquitoe'] and ("\tpopAdultos(total)") or "") .. 
				(log_globalOutput['devRateEggLarva'] and ("\teggToLarva") or "") .. 
				(log_globalOutput['devRateLarvaPupa'] and ("\tlarvaToPupa") or "") .. 
				(log_globalOutput['devRatePupaAdult'] and ("\tlarvaToPupa") or "") .. 
			"\n";
logFileGlobalOutput:write(logGR_header);

log_individualOutput = {}
log_individualOutput['temperature'] = INDIVIDUAL_TEMP
log_individualOutput['cellx'] = rawlen(INDIVIDUAL_CELL) ~= 0
log_individualOutput['celly'] = rawlen(INDIVIDUAL_CELL) ~= 0
log_individualOutput['oviposition'] = INDIVIDUAL_OVIP
log_individualOutput['popEggs'] = INDIVIDUAL_EGGS
log_individualOutput['popLarvae'] = INDIVIDUAL_LARVAE
log_individualOutput['popPupae'] = INDIVIDUAL_PUPAE
log_individualOutput['popMosquitoe'] = INDIVIDUAL_MOSQUITOES
-- cells from where the results will be saved, identified by x,y position of each cell {x, y} - eg. {x1, y1}, {x2, y2}
log_individualOutput['cells'] = INDIVIDUAL_CELL

logIR_header = "t" .. (log_individualOutput['temperature'] and ("\ttemperature") or "") .. 
					  (log_individualOutput['cellx'] and ("\tcellX_x") or "") .. 
					  (log_individualOutput['celly'] and ("\tcellY_y") or "") .. 
					  (log_individualOutput['oviposition'] and ("\tovipostos") or "") .. 
					  (log_individualOutput['popEggs'] and ("\tpopOvos(total)") or "") .. 
					  (log_individualOutput['popLarvae'] and ("\tpopLarvas(total)") or "") .. 
					  (log_individualOutput['popPupae'] and ("\tpopPupas(total)") or "") .. 
					  (log_individualOutput['popMosquitoe'] and ("\tpopAdultos(total)") or "") .. 
				"\n";
logFileIndividualOutput:write(logIR_header);


dt = 1			-- one day
UPPER = dt*7	-- week
DELTA = dt/ODE	-- it can vary as needed

R = 1.98
TabEntalpia = {
				{0.24,10798,100000,14184},
				{0.2088,26018,55990,304.6},
				{0.384,14931,-472379,148},
				{0.216,15725,1756481,447.2},
				{0.372,15725,1756481,447.2}
			}

if (CC_POP_TYPE == "Larvae") then
	CC_populationType = 2
else 
	if (CC_POP_TYPE == "Mosquitoes") then
		CC_populationType = 4
	else 
		CC_populationType = 0
	end
end

CC_efRate_Zg = 0; --Degree of phenotypic resistance conferred by genotype: 0 or 1

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

forEachCell(cs,
	function(cell)
		cell.Oviposicao = 0
		cell.Ovos = DAT_EGGS
		cell.Larvas = DAT_LARVAE
		cell.Pupas = DAT_PUPAE
		cell.Adultos = DAT_MOSQUITOES
		cell.focus = 0

        cell.CapacidadeArtificial = K;

        cell.CapacidadeSuporte = cell.CapacidadeArtificial;
        cell.CapacidadeSuporteOrig = cell.CapacidadeSuporte;
        cell.MortalidadeArtificial = 0;

        cell.past.Oviposicao = cell.Oviposicao;
        cell.past.Ovos = cell.Ovos;
        cell.past.Larvas = cell.Larvas;
        cell.past.Pupas = cell.Pupas;
        cell.past.Adultos = cell.Adultos;
        cell.past.CapacidadeSuporte = cell.CapacidadeSuporte;
        cell.past.CapacidadeArtificial = cell.CapacidadeArtificial;
        cell.past.CapacidadeSuporteOrig = cell.CapacidadeSuporteOrig;
        return true;
    end
);
-------------------------------------------------------------------------------------- ]]


if(DEBUG_MODE) then print("-- DEBUG MODE"); end;
if(DEBUG_MODE) then print("start"); end;

----------------------------------------------------------------------------------------------------
-- Auxiliary Functions
----------------------------------------------------------------------------------------------------
-- TODO: PERGUNTAR AO TIAGO DE ONDE TIROU ESTA FUNÇÃO
-- Generating random number
GLOBAL_RANDOM_SEED = os.time();
function randomNumber( limINF, limSUP )
   local a = 16807.000
   local m = 2147483647.000
   local q = 127773
   local r = 2836

   local x_div_q = math.floor( GLOBAL_RANDOM_SEED/q );
   local x_mod_q = math.mod(GLOBAL_RANDOM_SEED, q);
   local x_new = a* x_mod_q - r*x_div_q;
   if (x_new > 0) then  GLOBAL_RANDOM_SEED = x_new; else GLOBAL_RANDOM_SEED  = x_new + m; end
   number = GLOBAL_RANDOM_SEED/m;
   number = math.floor(limINF + number*((limSUP - limINF)-1));
   return number;
end

-- calculating precipitation: senoidal parameter
PI = 3.14;
FREQUENCY = 1/52;
idxTab = 0;
function precipitation(t, Amp, DeslocX, DeslocY) 
	return Amp * math.sin(2 * PI * idxTab * FREQUENCY + DeslocX) + DeslocY; 
end;

----------------------------------------------------------------------------------------------------
-- Load input file with model's configuration
----------------------------------------------------------------------------------------------------
-- 1) Configuration for model execution - PATH / LOG / DEBUG_MODE
-- 2) Input variables of model
-- 3) Database and obsever
-- 4) Error
--dofile("C:\\DengueME\\workspace\\integrated\\integrated_model_input.lua");

---------------------------------------------------------------------------------------------------
-- MODEL
----------------------------------------------------------------------------------------------------

-- cell = {};
-- cell.Oviposicao = 0;
-- cell.Ovos = 50;															-- VEM DO INPUT
-- cell.Larvas = 0;
-- cell.Pupas = 0;
-- cell.Adultos = 0;

-- cell.past = {};
-- cell.past.Oviposicao = cell.Oviposicao;
-- cell.past.Ovos = cell.Ovos;
-- cell.past.Larvas = cell.Larvas;
-- cell.past.Pupas = cell.Pupas;
-- cell.past.Adultos = cell.Adultos;

valormaximo = 0;
maximo_oviposicao = 0; maximo_ovos = 0; maximo_larvas = 0; maximo_pupas = 0; maximo_adultos = 0;
total_oviposition = 0; total_eggs = 0; total_larvae = 0; total_pupae = 0; total_mosquitoe = 0;
function model(event)
	t = event:getTime()
	--for t = SIMULATION_TIME_START, SIMULATION_TIME_END, 1 do	
		
		-- Used to get the index of the table of temperatures
		if( t == 0) then idxTab = 0; else idxTab = math.ceil(t); end
	--	idxTab = 1 + math.mod( idxTab, #Temp);									-- lua 5.1 / TerraME 1.1.2
		idxTab = 1 + idxTab % #Temp;											-- lua 5.2 / TerraME 1.2.1
		
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
		
		if(DEBUG_MODE) then io.flush(); print(t..": running dynamic model inside each cell"); end;

		total_oviposition = 0; total_eggs = 0; total_larvae = 0; total_pupae = 0; total_mosquitoe = 0;
		-- BEGIN FOREACHCELL
		forEachCell(cs, 
			function(cell)
			
				-- CONTROLE MECANICO
				-- ONDE 
				for countCellsMC = 1, #MC_cellsToApplyControl, 1 do
					--print(countCellsMC..":"..cellsToApplyControl[countCellsMC][1] .. "," .. cellsToApplyControl[countCellsMC][2]);
					
					-- Apply mechanical control to a cell {c.x, c.y}
					if (#MC_cellsToApplyControl[countCellsMC] == 2) then
						if (cell.x == MC_cellsToApplyControl[countCellsMC][1] and cell.y == MC_cellsToApplyControl[countCellsMC][2]) then 
							cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig;
							-- QUANDO
							for countTimeMC = 1, #MC_timeToApplyControl, 1 do
								if (#MC_timeToApplyControl[countTimeMC] == 1) then
									if (t == MC_timeToApplyControl[countTimeMC][1]) then
										print("\t"..MC_timeToApplyControl[countTimeMC][1]..":\tApplying Mechanical Control at cell: "..MC_cellsToApplyControl[countCellsMC][1] .. "," .. MC_cellsToApplyControl[countCellsMC][2]);
										cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig * MC_rate;
									end;
								end;
								if (#MC_timeToApplyControl[countTimeMC] == 2) then
									if (MC_timeToApplyControl[countTimeMC][1] <= t and t <= MC_timeToApplyControl[countTimeMC][2]) then
										print("\t["..MC_timeToApplyControl[countTimeMC][1] .. "," .. MC_timeToApplyControl[countTimeMC][2].."]:\tApplying Mechanical Control at cell: "..MC_cellsToApplyControl[countCellsMC][1] .. "," .. MC_cellsToApplyControl[countCellsMC][2]);
										cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig * MC_rate;
									end;
								end;
							end;
							
						end;
					
					end;
					
					-- Apply mechanical control to a region {c1.x, c1.y, c2.x, c2.y}
					if (#MC_cellsToApplyControl[countCellsMC] == 4) then
						if (cell.x >= MC_cellsToApplyControl[countCellsMC][1] and cell.x <= MC_cellsToApplyControl[countCellsMC][3] and
						    cell.y >= MC_cellsToApplyControl[countCellsMC][2] and cell.y <= MC_cellsToApplyControl[countCellsMC][4]) then 
							cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig;
							-- QUANDO
							for countTimeMC = 1, #MC_timeToApplyControl, 1 do
								if (#MC_timeToApplyControl[countTimeMC] == 1) then
									if (t == MC_timeToApplyControl[countTimeMC][1]) then
										print("\t"..MC_timeToApplyControl[countTimeMC][1]..":\tApplying Mechanical Control at cell: "..MC_cellsToApplyControl[countCellsMC][1] .. "," .. MC_cellsToApplyControl[countCellsMC][2]);
										cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig * MC_rate;
									end;
								end;
								if (#MC_timeToApplyControl[countTimeMC] == 2) then
									if (MC_timeToApplyControl[countTimeMC][1] <= t and t <= MC_timeToApplyControl[countTimeMC][2]) then
										print("\t["..MC_timeToApplyControl[countTimeMC][1] .. "," .. MC_timeToApplyControl[countTimeMC][2].."]:\tApplying Mechanical Control at cell: "..MC_cellsToApplyControl[countCellsMC][1] .. "," .. MC_cellsToApplyControl[countCellsMC][2]);
										cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig * MC_rate;
									end;
								end;
							end;
						end;
					
					end;
				end;
				
				-- CONTROLE QUÍMICO
				local MORT_ART = 0; local MORT_ART_LARVA = 0; local MORT_ART_ADULT = 0;
				-- ONDE 
				for countCellsCC = 1, #CC_cellsToApplyControl, 1 do
					--print(countCellsCC..":"..cellsToApplyControl[countCellsCC][1] .. "," .. cellsToApplyControl[countCellsCC][2]);
					
					-- Apply chemical control to a cell {c.x, c.y}
					if (#CC_cellsToApplyControl[countCellsCC] == 2) then
						if (cell.x == CC_cellsToApplyControl[countCellsCC][1] and cell.y == CC_cellsToApplyControl[countCellsCC][2]) then 
							--cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig;
							-- QUANDO
							for countTimeCC = 1, #CC_timeToApplyControl, 1 do
								if (#CC_timeToApplyControl[countTimeCC] == 1) then
									if (t == CC_timeToApplyControl[countTimeCC][1]) then
										ti = CC_timeToApplyControl[countTimeCC][1];
										rate = effectiveness_rate((t - ti), CC_efRate_Ta, CC_efRate_K, CC_efRate_Zg)
										MORT_ART = rate;
										print("\t"..CC_timeToApplyControl[countTimeCC][1]..":\tApplying Chemical Control at cell: "..CC_cellsToApplyControl[countCellsCC][1] .. "," .. CC_cellsToApplyControl[countCellsCC][2] .. "\trate: "..MORT_ART);
									end;
								end;
								if (#CC_timeToApplyControl[countTimeCC] == 2) then
									if (CC_timeToApplyControl[countTimeCC][1] <= t and t <= CC_timeToApplyControl[countTimeCC][2]) then
										ti = CC_timeToApplyControl[countTimeCC][1];
										rate = effectiveness_rate((t - ti), CC_efRate_Ta, CC_efRate_K, CC_efRate_Zg)
										MORT_ART = rate;
										print("\t["..CC_timeToApplyControl[countTimeCC][1] .. "," .. CC_timeToApplyControl[countTimeCC][2].."]:\tApplying Chemical Control at cell: "..CC_cellsToApplyControl[countCellsCC][1] .. "," .. CC_cellsToApplyControl[countCellsCC][2] .. "\trate: "..MORT_ART);
									end;
								end;
							end;
						end;
					end;
					
					-- Apply chemical control to a region {c1.x, c1.y, c2.x, c2.y}
					if (#CC_cellsToApplyControl[countCellsCC] == 4) then
						if (cell.x >= CC_cellsToApplyControl[countCellsCC][1] and cell.x <= CC_cellsToApplyControl[countCellsCC][3] and
						    cell.y >= CC_cellsToApplyControl[countCellsCC][2] and cell.y <= CC_cellsToApplyControl[countCellsCC][4]) then 
							--cell.CapacidadeSuporte = cell.CapacidadeSuporteOrig;
							-- QUANDO
							for countTimeCC = 1, #CC_timeToApplyControl, 1 do
								if (#CC_timeToApplyControl[countTimeCC] == 1) then
									if (t == CC_timeToApplyControl[countTimeCC][1]) then
										ti = CC_timeToApplyControl[countTimeCC][1];
										rate = effectiveness_rate((t - ti), CC_efRate_Ta, CC_efRate_K, CC_efRate_Zg)
										MORT_ART = rate;
										print("\t"..CC_timeToApplyControl[countTimeCC][1]..":\tApplying Chemical Control at region: "..CC_cellsToApplyControl[countCellsCC][1] .. "," .. CC_cellsToApplyControl[countCellsCC][2] .."-".. CC_cellsToApplyControl[countCellsCC][3] .. "," .. CC_cellsToApplyControl[countCellsCC][4] .. "\trate: "..MORT_ART);
									end;
								end;
								if (#CC_timeToApplyControl[countTimeCC] == 2) then
									if (CC_timeToApplyControl[countTimeCC][1] <= t and t <= CC_timeToApplyControl[countTimeCC][2]) then
										ti = CC_timeToApplyControl[countTimeCC][1];
										rate = effectiveness_rate((t - ti), CC_efRate_Ta, CC_efRate_K, CC_efRate_Zg)
										MORT_ART = rate;
										print("\t"..CC_timeToApplyControl[countTimeCC][1]..":\tApplying Chemical Control at region: "..CC_cellsToApplyControl[countCellsCC][1] .. "," .. CC_cellsToApplyControl[countCellsCC][2] .."-".. CC_cellsToApplyControl[countCellsCC][3] .. "," .. CC_cellsToApplyControl[countCellsCC][4] .. "\trate: "..MORT_ART);
									end;
								end;
							end;
						end;
					end;
				end;
				if (MORT_ART > 0) then
					if (CC_populationType == 2) then MORT_ART_LARVA = MORT_ART; end;
				    if (CC_populationType == 4) then MORT_ART_ADULT = MORT_ART; end;
				end;
				
				---------------------------------------------------------------------------------------------------------
				-- ODE of populations
				---------------------------------------------------------------------------------------------------------
				oviposicao  = 0 ;
				auxTeste = 0;
				-- M ~ mortality rate
				-- M1 = eggs; M2 = larvae; M3 = pupae; M4 = mosquitoes
				-- developmental rates
				-- txTransOv = oviposition: fixed; txTransO = egg to larva; txTransL = larva to pupa; txTransP = pupa to adult
				cell.Ovos, cell.Larvas, cell.Pupas, cell.Adultos = d{
					{
						function(t, q)
							--oviposicao = txTransOv*cell.past.Adultos*(1- (q[1]/K));
							oviposicao = txTransOv*q[4]*(1- (q[1]/cell.CapacidadeSuporte));
							cell.Oviposicao = oviposicao;
							auxTeste = M1*q[1];
							return oviposicao - (txTransO*q[1]  + M1*q[1]) 
						end, 
						function(t, q) 
							return txTransO*q[1] - ( txTransL*q[2] + (M2 + MORT_ART_LARVA)*q[2] )
						end,
						function(t, q)  
							return txTransL*q[2] - (txTransP*q[3] +  M3*q[3] ) 
						end,
						function(t, q)
							return txTransP*q[3] - ((M4 + MORT_ART_ADULT)*q[4]) 
						end
					},
					{cell.past.Ovos, cell.past.Larvas, cell.past.Pupas, cell.past.Adultos}, 
					0, UPPER, DELTA 
	--		0, t, DELTA 
				}
				
				if (DEMAND_POPULATION == 0) then
					cell.focus = cell.Oviposicao * DEMAND_SCALE;
				else 
					if (DEMAND_POPULATION == 1) then
						cell.focus = cell.Ovos * DEMAND_SCALE;
					else 
						if (DEMAND_POPULATION == 2) then
							cell.focus = cell.Larvas * DEMAND_SCALE;
						else
							if (DEMAND_POPULATION == 3) then
								cell.focus = cell.Pupas * DEMAND_SCALE;
							else
								if (DEMAND_POPULATION == 4) then
									cell.focus = cell.Adultos * DEMAND_SCALE;
								end;
							end;
						end;
					end;
				end;
				
				cell.past.Oviposicao = cell.Oviposicao;
				cell.past.Ovos = cell.Ovos;
				cell.past.Larvas = cell.Larvas;
				cell.past.Pupas = cell.Pupas;
				cell.past.Adultos = cell.Adultos;
				
				-- identify the maximum value of each population
				if(DEBUG_MODE) then
					if (cell.Oviposicao > maximo_oviposicao) then maximo_oviposicao = cell.Oviposicao; end;
					if (cell.Ovos > maximo_ovos) then maximo_ovos = cell.Ovos; end;	
					if (cell.Larvas > maximo_larvas) then maximo_larvas = cell.Larvas; end;	
					if (cell.Pupas > maximo_pupas) then maximo_pupas = cell.Pupas; end;	
					if (cell.Adultos > maximo_adultos) then maximo_adultos = cell.Adultos; end;	
				end;
						
				total_oviposition = cell.Oviposicao + total_oviposition;
				total_eggs = cell.Ovos + total_eggs;
				total_larvae = cell.Larvas + total_larvae; 
				total_pupae = cell.Pupas + total_pupae; 
				total_mosquitoe = cell.Adultos + total_mosquitoe;
				 
				-- Report: save the simulation results
				if( t >= SIMULATION_TIME_START_LOG) and (t <= SIMULATION_TIME_END_LOG) then
				 
					-- save results for individual cells
					for countCellsMC = 1, #log_individualOutput['cells'], 1 do
						-- Save results for cell {c.x, c.y}
						if (#log_individualOutput['cells'][countCellsMC] == 2) then
							if (cell.x == log_individualOutput['cells'][countCellsMC][1] and cell.y == log_individualOutput['cells'][countCellsMC][2]) then 
								print(countCellsMC..":"..log_individualOutput['cells'][countCellsMC][1] .. "," .. log_individualOutput['cells'][countCellsMC][2]);
								-- save individual results
								outputIRstr =   t .. (log_individualOutput['temperature'] and ("\t"..Temp[idxTab]) or "") .. 
													 (log_individualOutput['cellx'] and ("\t"..cell.x) or "") .. 
													 (log_individualOutput['celly'] and ("\t"..cell.y) or "") .. 
													 (log_individualOutput['oviposition'] and ("\t"..cell.Oviposicao) or "") .. 
													 (log_individualOutput['popEggs'] and ("\t"..cell.Ovos) or "") .. 
													 (log_individualOutput['popLarvae'] and ("\t"..cell.Larvas) or "") .. 
													 (log_individualOutput['popPupae'] and ("\t"..cell.Pupas) or "") .. 
													 (log_individualOutput['popMosquitoe'] and ("\t"..cell.Adultos) or "") .. 
												"\n";
								logFileIndividualOutput:write(outputIRstr);
							end;
						end;
					end;
				end;

				return true;
			end
		);
		-- END FOREACHCELL
		cs:synchronize();
		
		if(DEBUG_MODE) then 
			print("\tvalores maximos\n\tOviposicao:" .. maximo_oviposicao .. " - Ovos:" .. maximo_ovos .. " - Larvas:" .. maximo_larvas .. "- Pupas:" .. maximo_pupas .. " - Adultos:" .. maximo_adultos);
		end;
		
		-- Report: save the simulation results
		if( t >= SIMULATION_TIME_START_LOG) and (t <= SIMULATION_TIME_END_LOG) then
	--		aux = (t+1) % 1900;
	--		logFileError:write(t.."\t"..oviposicao_simulada_total[t].."\t".. oviposicao_real_total[aux] .. "\n");
	--		logFile:write(t.."\t"..oviposicao.."\t"..cell.Ovos.."\t"..cell.Larvas.."\t"..cell.Pupas.."\t"..cell.Adultos.."\n" );
			-- save global results
			outputGRstr =   t .. (log_globalOutput['temperature'] and ("\t"..Temp[idxTab]) or "") .. 
								 (log_globalOutput['oviposition'] and ("\t"..total_oviposition) or "") .. 
						         (log_globalOutput['popEggs'] and ("\t"..total_eggs) or "") .. 
								 (log_globalOutput['popLarvae'] and ("\t"..total_larvae) or "") .. 
								 (log_globalOutput['popPupae'] and ("\t"..total_pupae) or "") .. 
								 (log_globalOutput['popMosquitoe'] and ("\t"..total_mosquitoe) or "") .. 
								 (log_globalOutput['devRateEggLarva'] and ("\t"..txTransO) or "") .. 
								 (log_globalOutput['devRateLarvaPupa'] and ("\t"..txTransL) or "") .. 
								 (log_globalOutput['devRatePupaAdult'] and ("\t"..txTransP) or "") .. 
							"\n";

			logFileGlobalOutput:write(outputGRstr);

			cs:notify()
		end;
		
	--end;
end;

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

print("READY");
io.flush();

os.exit();

-- TODO: VERIFICAR NÚMEROS NEGATIVOS PARA POPULAÇÃO QUANDO CAPACIDADE DE SUPORTE É PRÓXIMA DE ZERO

-- sortear celulas aleatoriamente para mudar MC