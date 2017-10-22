# DengueME Models Library
# @id r_sir_basic_model
# @name SIR Basic Model
# @version 1.0
# @interpreter R v3.4.1
# @example A Susceptible-Infected-Recovered (SIR) basic model
# @authors Fellipe Prado, Tiago Lima
# @description For a description of such model, please visit http://en.wikipedia.org/wiki/Epidemic_model

# DEPENDENCIES
library('deSolve')

# ODE SIR function
odeSIR <- function(times, state, parameters){

   with(as.list(c(state, parameters)), {
      
      Nh <- Sh + Ih + Rh
      
      dSh <- -beta * ( (Sh * Ih)/Nh )
      dIh <- beta * ( (Sh * Ih)/Nh ) - (gamma * Ih)
      dRh <- gamma * Ih
      
      return(list(c(dSh, dIh, dRh), Nh = Nh))
   })
}

# Initial conditions of the population
init <- c(Sh = Sh, Ih = Ih, Rh = Rh)
parameters <- c(beta = beta, gamma = gamma)
times <- seq(from = 0, to = steps, by = 1)

simulation <- as.data.frame(lsoda(y = init, times = times, func = odeSIR, parms = parameters))
head(simulation)
tail(simulation)

# Results
if (output) {
   if (outChart & length(outChartSelect) > 0) {
      plot(x = simulation$time, y = simulation[,c(outChartSelect[1])], type = outChartStyle[1], col=outChartColor[1], xlab="Time", ylab = "Humans")
      if (length(outChartSelect) >= 2)
         for (i in 2:length(outChartSelect))
            lines(x = simulation$time, simulation[,c(outChartSelect[i])], type = outChartStyle[i], col=outChartColor[i])
   }
   if (outTextScreen) {
      lastRow <- simulation[nrow(simulation),]
      row.names(lastRow) <- NULL
      View(lastRow[ c("time", outTextScreenSelect) ])
   }
   if (outVisualTable)
      View(simulation[ c("time", outVisualTableSelect) ] )
   if (outLog)
      write.table(x = simulation[ c("time", outLogSelect) ], file = outLogFile, append = !outLogOverwrite, quote = FALSE, sep = outLogSeparator, col.names = TRUE)
}