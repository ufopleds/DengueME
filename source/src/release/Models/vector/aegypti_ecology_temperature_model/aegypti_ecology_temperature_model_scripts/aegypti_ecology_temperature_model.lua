-- @example A vector (Aedes aegypti) ecology basic model. 
-- @version TerraME 1.6
-- @authors Raquel Lana, Tiago Carneiro, Claudia Codeço, Tiago Lima
-- @description This is an adapted version of the model developed by Lana et al. 2014. For a description of such model please see the paper "Seasonal and nonseasonal dynamics of Aedes aegypti in Rio de Janeiro, Brazil: fitting mathematical models to trap data" (doi:10.1016/j.actatropica.2013.07.025) <<http://www.sciencedirect.com/science/article/pii/S0001706X13002052>>


RESULTS_PATH 	= BASE_PATH,
logFile = io.open(RESULTS_PATH.. "\\" ..RESULTS_FILE .. ".csv", "w+"),
logFile:write("t\tTemp\tEggs\tLarvae\tPupae\tAdults\n"),

----------------------------------------------------------------------------------------------------
-- CONSTANTS (MODEL PARAMETERS) 
----------------------------------------------------------------------------------------------------
-- differential equation function
EDO_INF = DT         -- day (1)
EDO_UPPER = UPPER    -- week (7)
EDO_DELTA = DELTA    -- it can varies as needed

-- parameters used by thermodynamic equation
R = 1.98              -- universal gas constant
-- Development rates: kinetics function models (see Sharpe and DeMichele (1977), Schoofield et al. (1981) and Focks et al. (1993a))
TabEntalpia = {
    {0.24,10798,100000,14184},
    {0.2088,26018,55990,304.6},
    {0.384,14931,-472379,148},
    {0.216,15725,1756481,447.2},
    {0.372,15725,1756481,447.2}
}

-- developmental rates
txTransO = 0 -- egg to larva
txTransL = 0 -- larva to pupa
txTransP = 0 -- pupa to adult
--txTransOv = 1.0 -- oviposition: fixed

----------------------------------------------------------------------------------------------------
-- INPUTS (MODEL AND SIMULATION PARAMETERS) 
----------------------------------------------------------------------------------------------------

-- simulation and report 
simulation_start = SIMULATION_START
simulation_end = SIMULATION_END
simulation_report_start = SIMULATION_REPORT_START
simulation_report_end = SIMULATION_REPORT_END

-- model inputs
Temp = TEMP

world = Cell {
    eggs = INIT_EGG,
    larvae = INIT_LARVA, 
    pupae = INIT_PUPA,
    adults = INIT_ADULT,
    population = INIT_EGG + INIT_LARVA + INIT_PUPA + INIT_ADULT,
    carrying_cap = CC,
    tx_ovip = TX_OVIP,  -- oviposition rate (per day per mosquito) 
    u_eggs = MORT_EGG,  -- eggs mortality rate (1/100)
    u_larvae = MORT_LARVA, -- larvae mortality rate (1/3)
    u_pupae = MORT_PUPA, -- pupae mortality rate (1/70)
    u_adults = MORT_ADULT -- adults mortality rate (1/17.5)
}
world:synchronize()

-- report
chartVector = Chart { 
    target = world, 
    select = {"eggs", "larvae", "pupae", "adults", "population"}, 
    color = {"blue", "red", "yellow", "black", "gray"}
}
obsText = TextScreen {
    target = world,
    select = {"eggs", "larvae", "pupae", "adults", "population"},
}
--world:notify()

t = Timer {
   Event {
      start = simulation_start, period = 1, priority = 0,  
      action = function()
         
         --Para comparar uma tabela: Amostra
         if( t:getTime() == 0) then idxTab = 0, else idxTab = math.ceil(t:getTime()), end
         
         idxTab = 1 + (idxTab % #Temp),
         
         temp = Temp[idxTab],
         temp = Temp[idxTab] + 273.15,
         
         --Equação Termodinamica proposta por Sharpe e DeMichelle
         txTransO = TabEntalpia[1][1]*((temp/298)*math.exp((TabEntalpia[1][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[1][3]/R)*(1/TabEntalpia[1][4]-1/temp)))),
         txTransL = TabEntalpia[2][1]*((temp/298)*math.exp((TabEntalpia[2][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[2][3]/R)*(1/TabEntalpia[2][4]-1/temp))))
         txTransP = TabEntalpia[3][1]*((temp/298)*math.exp((TabEntalpia[3][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[3][3]/R)*(1/TabEntalpia[3][4]-1/temp))))
         if ( Temp[idxTab] < 4.85 or Temp[idxTab] > 33) then
            txTransO = 0,
            txTransL = 0,
            txTransP = 0,
         end
         
         ---------------------------------------------------------------------------------------------------------
         -- Model
         ---------------------------------------------------------------------------------------------------------          
         world.eggs, world.larvae, world.pupae, world.adults = d {
            {
               function(t, q)
                  local oviposicao = world.tx_ovip * q[4]*(1- ( q[1] / world.carrying_cap )),
                  return oviposicao - (txTransO*q[1]  + world.u_eggs * q[1]) 
               end,
               function(t, q)
                  return txTransO*q[1] - ( txTransL*q[2] + world.u_larvae * q[2] )
               end,
               function(t, q)
                  return txTransL*q[2] - ( txTransP*q[3] +  world.u_pupae * q[3] )
               end,
               function(t, q)
                  return txTransP*q[3] - ( world.u_adults * q[4]) 
               end               
            },
            {world.past.eggs, world.past.larvae, world.past.pupae, world.past.adults},
            EDO_INF, EDO_UPPER, EDO_DELTA
         }
         
         world.population = world.eggs + world.larvae + world.pupae + world.adults 
                  
         -- Report: save the simulation results
         if (t:getTime() >= simulation_report_start) and (t:getTime() <= simulation_report_end) then 
            world:notify(t:getTime())
            logFile:write(t:getTime() .. "\t" .. Temp[idxTab].. "\t" .. "\t" ..world.eggs.."\t"..world.larvae.."\t"..world.pupae.."\t"..world.adults.."\n" ),
         end
         
      end
   }
}

t:execute(simulation_end)
