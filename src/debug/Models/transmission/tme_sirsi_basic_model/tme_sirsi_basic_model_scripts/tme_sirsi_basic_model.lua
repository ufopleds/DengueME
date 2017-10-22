-- DengueME Models Library
-- @id tme_sirsi_basic_model
-- @name SIR-SI Basic Model
-- @version 1.0
-- @interpreter TerraME 2.0-RC-4
-- @example A Susceptible-Infected-Recovered-Susceptible-Infected (SIR-SI) basic model.
-- @authors Tiago Lima, Lucas Saraiva
-- @description SIR-SI basic model is a simplified version of the model proposed by Nishiura (2006). For a complete description of such model please see the paper Nishiura (2006), "Mathematical and Statistical Analyses of the Spread of Dengue", Dengue Bulletin, Volume 30, 2006.

world = Model {
   Sh = Sh,
   Ih = Ih, 
   Rh = Rh,
   Nh = Sh + Ih + Rh,
   Sv = Sv,
   Iv = Iv,
   Nv = Sv + Iv,
   biting = biting,
   gamma = gamma,
   betah = betah,
   betav = betav,
   
   finalTime = steps,
        
   init = function(model)
      
      -- Output: Chart
      if (outChart) then
         model.chart = Chart { target = model, select = outChartSelect, label= outChartLabel, style = outChartStyle, color = outChartColor, title = outChartTitle, xLabel = outChartXLabel, yLabel = outChartYLabel }
      end
      
      if (outChartHuman) then
         model.chartHuman = Chart { target = model, select = outChartHumanSelect, label= outChartHumanLabel, style = outChartHumanStyle, color = outChartHumanColor, title = outChartHumanTitle, xLabel = outChartHumanXLabel, yLabel = outChartHumanYLabel }
      end
      
      if (outChartVector) then
         model.chartVector = Chart { target = model, select = outChartVectorSelect, label= outChartVectorLabel, style = outChartVectorStyle, color = outChartVectorColor, title = outChartVectorTitle, xLabel = outChartVectorXLabel, yLabel = outChartVectorYLabel }
      end
      
      -- Output: TextScreen
      if (outTextScreen) then         
         model.text = TextScreen { target = model, select = outTextScreenSelect }
      end
      
      -- Output: VisualTable
      if (outVisualTable) then         
         model.text = VisualTable { target = model, select = outVisualTableSelect }
      end
      
      -- Output: Log
      if (outLog) then         
         model.text = Log { target = model, select = outLogSelect, file = outLogFile, separator = outLogSeparator, overwrite = outLogOverwrite }
      end
      
      if (output) then
         model:notify()
      end
      
      model.timer = Timer{
         Event{action = function(ev)
            local new_human_infections = (model.betah * model.biting/model.Nh) * model.Sh * model.Iv
            if new_human_infections > model.Sh then
               new_human_infections = model.Sh
            end
            
            local new_vector_infections = (model.betav * model.biting/model.Nh) * model.Sv * model.Ih
            if new_vector_infections > model.Sv then
               new_vector_infections = model.Sv
            end
                        
            model.Rh = model.Rh + (model.gamma * model.Ih)
            model.Ih = model.Ih + new_human_infections - (model.gamma * model.Ih)
            model.Sh = model.Sh - new_human_infections
            model.Nh = model.Sh + model.Ih + model.Rh
            
            model.Iv = model.Iv + new_vector_infections
            model.Sv = model.Sv - new_vector_infections
            model.Nv = model.Sv + model.Iv
            
            if (output) then
               model:notify(ev)
            end
                
         end}
      }
   end
}

world:run()