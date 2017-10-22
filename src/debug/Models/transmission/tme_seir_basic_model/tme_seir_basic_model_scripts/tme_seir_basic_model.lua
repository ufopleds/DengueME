-- DengueME Models Library
-- @id tme_seir_basic_model
-- @name SEIR Basic Model
-- @version 1.0
-- @interpreter TerraME 2.0-RC-4
-- @example A Susceptible-Exposed-Infectious-Recovered (SEIR) basic model
-- @authors Fellipe Prado, Tiago Lima
-- @description For a description of such model, please visit http://en.wikipedia.org/wiki/Epidemic_model

world = Model {
   Sh = Sh,
   Eh = Eh,
   Ih = Ih, 
   Rh = Rh,
   Nh = Sh + Eh + Ih + Rh,
   beta = beta,
   sigma = sigma,
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
            model.Sh = model.Sh - (model.beta * model.Sh * (model.Ih / model.Nh ))
            model.Eh = model.Eh + (model.beta * model.Sh * (model.Ih / model.Nh )) - (model.sigma * model.Eh)
            model.Ih = model.Ih + (model.sigma * model.Eh) - (model.gamma * model.Ih)
            model.Rh = model.Rh + (model.gamma * model.Ih)
            
            if (output) then
               model:notify(ev)
            end
            
         end}
      }
   end
}

world:run()