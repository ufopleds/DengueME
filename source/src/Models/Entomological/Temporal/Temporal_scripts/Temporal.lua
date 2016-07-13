-- Temporal Model for Aedes aegypti population dynamic
-- Raquel Martins Lana, Tiago Garcia de Senna Carneiro, Cláudia Codeço, Tiago França Melo de Lima
-- Description:
-- Developed using TerraME 1.1.2
-- Modelo Temporal 
-- Calibrador: 
-- Dados reais de temperatura e oviposição

-------------------------------------------------------------------------------------- [[
RESULTS_PATH = BASE_PATH .. "/" .. RESULTS_DIR

logFile = io.open(RESULTS_PATH .. "/" .. RESULTS_FILE, "w+");

dt = 1			-- one day
UPPER = dt*7	-- week
DELTA = dt/ODE	-- it can vary as needed

txTransOv = 1.0;	-- oviposition: fixed

R = 1.98
TabEntalpia = {
				{0.24,10798,100000,14184},
				{0.2088,26018,55990,304.6},
				{0.384,14931,-472379,148},
				{0.216,15725,1756481,447.2},
				{0.372,15725,1756481,447.2}
			}

erroMIN = 10e34;

cell = {};
cell.Ovos = AmostraOvos[INIT_EGGS]
cell.Larvas = INIT_LARVAE
cell.Pupas = INIT_PUPAE
cell.Adultos = INIT_ADULTS

cell.past = {}
cell.past.Ovos = cell.Ovos;
cell.past.Larvas = cell.Larvas;
cell.past.Pupas = cell.Pupas;
cell.past.Adultos = cell.Adultos;
-------------------------------------------------------------------------------------- ]]

if(DEBUG_MODE) then print("-- DEBUG MODE"); end;
if(DEBUG_MODE) then print("start"); end;


----------------------------------------------------------------------------------------------------
-- Auxiliary Functions
----------------------------------------------------------------------------------------------------



---------------------------------------------------------------------------------------------------
-- MODEL
----------------------------------------------------------------------------------------------------

somaErro = 0;
resultsByWeek = {}
function model(event)
	t = event:getTime()
	--for t = SIMULATION_TIME_START, SIMULATION_TIME_END, 1 do
		if(DEBUG_MODE) then io.flush(); print(t..": running temporal model"); end;
		--Para comparar uma tabela: AmostraOvos
		if( t == 0) then 
			idxTab = 0;
		else 
			idxTab = math.ceil(t); 
		end

		idxTab = 1 + idxTab%#Temp;
		if( idxTab == 1) then somaErro = 0; end

		temp = Temp[idxTab];
		temp = Temp[idxTab] + 273.15;
		--Equação Termodinamica proposta por Sharpe e DeMichelle
		txTransO = TabEntalpia[1][1]*((temp/298)*math.exp((TabEntalpia[1][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[1][3]/R)*(1/TabEntalpia[1][4]-1/temp))));
		txTransL = TabEntalpia[2][1]*((temp/298)*math.exp((TabEntalpia[2][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[2][3]/R)*(1/TabEntalpia[2][4]-1/temp))))
		txTransP = TabEntalpia[3][1]*((temp/298)*math.exp((TabEntalpia[3][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[3][3]/R)*(1/TabEntalpia[3][4]-1/temp))))
		if ( Temp[idxTab] < 4.85 or Temp[idxTab] > 33) then  
			txTransO = 0;
			txTransL = 0;
			txTransP = 0;
		end

		---------------------------------------------------------------------------------------------------------
		-- Modelo do primeiro sistema
		--------------------------------------------------------------------------------------------------------- 
		oviposicao = 0
		auxTeste = 0;
		-- M ~ mortality rate
		-- M1 = eggs; M2 = larvae; M3 = pupae; M4 = mosquitoes
		-- developmental rates
		-- txTransOv = oviposition: fixed; txTransO = egg to larva; txTransL = larva to pupa; txTransP = pupa to adult
		cell.Ovos, cell.Larvas, cell.Pupas, cell.Adultos = d{
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
			{cell.past.Ovos, cell.past.Larvas, cell.past.Pupas, cell.past.Adultos}, 
			0, UPPER, DELTA 
	--		0, t, DELTA 
		}

		mortOvos = cell.Ovos - cell.past.Ovos;
		pastOvos = cell.past.Ovos;
		cell.past.Ovos = cell.Ovos;
		cell.past.Larvas = cell.Larvas;
		cell.past.Pupas = cell.Pupas;
		cell.past.Adultos = cell.Adultos;
		
		-- Report: save the simulation results
		if( t >= SIMULATION_TIME_START_LOG) and (t <= SIMULATION_TIME_END_LOG) then
	--		local resto = math.ceil(t) - t;
	--		if(resto < dt) then  
				print("\tOvip: "..oviposicao.."\tO: "..cell.Ovos.."\tL: "..cell.Larvas.."\tP: "..cell.Pupas.."\tA: "..cell.Adultos);
				local Erro = (AmostraOvos[idxTab] - oviposicao)^2;  
				somaErro = somaErro + Erro;
			
				-- Relatorio
				logFile:write(t.."\t"..Temp[idxTab].."\t"..oviposicao.."\t"..AmostraOvos[idxTab].."\t"..Erro.."\t"..somaErro.."\t"..cell.Ovos.."\t"..pastOvos.."\t"..auxTeste.."\t"..mortOvos.."\n" );
	--		end;
		end;
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
		
somaErro = somaErro / (#AmostraOvos - 1);
--logFile:write(somaErro);
	
if( somaErro < erroMIN) then
	erroMIN = somaErro
	KMIN =  K;
end
    
logFile:close();	
print("K: " .. K);
print("erroMIN: " .. erroMIN);
print("READY!!!");