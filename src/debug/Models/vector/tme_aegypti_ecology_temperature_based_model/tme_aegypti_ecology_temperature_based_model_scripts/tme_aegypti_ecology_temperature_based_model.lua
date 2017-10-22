-- DengueME Models Library
-- @id tme_aegypti_ecology_temperature_based_model
-- @name Temperature-based vector ecology model
-- @version 1.0
-- @interpreter TerraME 2.0-RC-4
-- @example Temperature-based model of Aedes aegypti ecology
-- @authors Raquel Lana, Tiago Carneiro, Cláudia Codeço, Tiago Lima
-- @description An Aedes aegypti population model with four compartments representing (egg, larva, pupa and adult) with temperature-dependent transition rates. For a complete description of such model please see the paper Lana et al. (2014), "Seasonal and nonseasonal dynamics of Aedes aegypti in Rio de Janeiro, Brazil: Fitting mathematical models to trap data", Acta Tropica, Volume 129, 2014.

----------------------------------------------------------------------------------------------------
-- CONSTANTS (MODEL PARAMETERS) 
----------------------------------------------------------------------------------------------------
-- parameters used by thermodynamic equation
R = 1.98 -- universal gas constant
-- Development rates: kinetics function models (see Sharpe and DeMichele (1977), Schoofield et al. (1981) and Focks et al. (1993a))
TabEntalpia = {
    {0.24,10798,100000,14184},
    {0.2088,26018,55990,304.6},
    {0.384,14931,-472379,148},
    {0.216,15725,1756481,447.2},
    {0.372,15725,1756481,447.2}
}
-- developmental rates
txTransO = 0 -- egg to larva transition rate
txTransL = 0 -- larva to pupa transition rate
txTransP = 0 -- pupa to adult transition rate

world = Model {
   carrying_cap = carrying_cap,
   oviposition_rate = oviposition_rate,
   u_eggs = u_eggs,
   u_larvae = u_larvae,
   u_pupae = u_pupae,
   u_adults = u_adults,
      
   finalTime = steps,
   
   init = function(model)
      model.cs = Cell {
         temperature = 0,
         eggs = eggs,
         larvae = larvae, 
         pupae = pupae,
         adults = adults,
         population = eggs + larvae + pupae + adults
      }
      model.cs:synchronize()
      
      -- Output: Chart
      if (outChart) then
         model.chart = Chart { target = model.cs, select = outChartSelect, label= outChartLabel, style = outChartStyle, color = outChartColor, title = outChartTitle, xLabel = outChartXLabel, yLabel = outChartYLabel }
      end
            
      -- Output: TextScreen
      if (outTextScreen) then         
         model.text = TextScreen { target = model.cs, select = outTextScreenSelect }
      end
      
      -- Output: VisualTable
      if (outVisualTable) then         
         model.text = VisualTable { target = model.cs, select = outVisualTableSelect }
      end
      
      -- Output: Log
      if (outLog) then         
         model.text = Log { target = model.cs, select = outLogSelect, file = outLogFile, separator = outLogSeparator, overwrite = outLogOverwrite }
      end
      
      if (output) then
         model:notify()
      end
      
      model.timer = Timer{
         Event{ start = simulation_start, period = 1, priority = 0,
            action = function(ev)
               -- print(ev:getTime());
               
               if( ev:getTime() == 0) then idxTab = 0; else idxTab = math.ceil(ev:getTime()); end
               idxTab = 1 + (idxTab % #weeklyTemperature);
         
               -- temp = Temp[idxTab];
               temp = weeklyTemperature[idxTab] + 273.15;
         
               -- Thermodynamic Equation proposed by Sharpe and DeMichelle
               txTransO = TabEntalpia[1][1]*((temp/298)*math.exp((TabEntalpia[1][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[1][3]/R)*(1/TabEntalpia[1][4]-1/temp))));
               txTransL = TabEntalpia[2][1]*((temp/298)*math.exp((TabEntalpia[2][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[2][3]/R)*(1/TabEntalpia[2][4]-1/temp))));
               txTransP = TabEntalpia[3][1]*((temp/298)*math.exp((TabEntalpia[3][2]/R)*(1/298 - 1/temp))/(1 + math.exp((TabEntalpia[3][3]/R)*(1/TabEntalpia[3][4]-1/temp))));
               if ( weeklyTemperature[idxTab] < 4.85 or weeklyTemperature[idxTab] > 33) then
                  txTransO = 0;
                  txTransL = 0;
                  txTransP = 0;
               end
                              
               ---------------------------------------------------------------------------------------------------------
               -- EDO population model
               ---------------------------------------------------------------------------------------------------------          
               model.cs.eggs, model.cs.larvae, model.cs.pupae, model.cs.adults = d {
                  {
                     function(t, q)
                        local oviposicao = model.oviposition_rate * q[4]*(1- ( q[1] / model.carrying_cap ))
                        return oviposicao - (txTransO*q[1]  + model.u_eggs * q[1]) 
                     end,
                     function(t, q)
                        return txTransO*q[1] - ( txTransL*q[2] + model.u_larvae * q[2] )
                     end,
                     function(t, q)
                        return txTransL*q[2] - ( txTransP*q[3] +  model.u_pupae * q[3] )
                     end,
                     function(t, q)
                        return txTransP*q[3] - ( model.u_adults * q[4]) 
                     end               
                  },
                  {model.cs.past.eggs, model.cs.past.larvae, model.cs.past.pupae, model.cs.past.adults},
                  edo_dt, edo_upper, edo_delta
               }
               model.cs.population = model.cs.eggs + model.cs.larvae + model.cs.pupae + model.cs.adults
               model.cs.temperature = temp
               
               if (output) then
                  model.cs:notify(ev)
               end
                   
            end
         }
      }
   end
}

world:run()