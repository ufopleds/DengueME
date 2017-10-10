-- DengueME Models Library
-- @id tme_sir_basic_model
-- @name SIR Basic Model
-- @version 1.0
-- @interpreter TerraME 2.0-RC-4
-- @example A Susceptible-Infected-Recovered (SIR) basic model. 
-- @authors Tiago Lima, Lucas Saraiva
-- @description For a description of such model, please visit <<http://en.wikipedia.org/wiki/Epidemic_model>>

world = Model {
   Sh = Sh,
   Ih = Ih, 
   Rh = Rh,
   Nh = Sh + Ih + Rh,
   beta = beta,
   gamma = gamma,
   
   finalTime = steps,
        
   init = function(model)
      
      -- Output: Chart
      if (outChart) then
         model.chart = Chart { target = model, select = outChartSelect, label= outChartLabel, style = outChartStyle, color = outChartColor, title = outChartTitle, xLabel = outChartXLabel, yLabel = outChartYLabel }
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
            local new_infections = model.beta * ( model.Sh * model.Ih / model.Nh )    -- beta = infection_rate
            if new_infections > model.Sh then
               new_infections = model.Sh
            end
            
            model.Rh = model.Rh + (model.gamma * model.Ih)
            model.Ih = model.Ih + new_infections - (model.gamma * model.Ih)
            model.Sh = model.Sh - new_infections
            model.Nh = model.Sh + model.Ih + model.Rh
                
            if (output) then
               model:notify(ev)
            end
                
         end}
      }
   end
}

world:run()