# DengueME Models Library
# @id r_seir_basic_model
# @name SEIR Basic Model
# @version 1.0
# @interpreter R v3.4.1
# @example A Susceptible-Exposed-Infectious-Recovered (SEIR) basic model
# @authors Fellipe Prado, Tiago Lima
# @description For a description of such model, please visit http://en.wikipedia.org/wiki/Epidemic_model

# DEPENDENCIES
library('deSolve')

# ODE SEIR function
odeSEIR <- function(times, state, parameters){

   with(as.list(c(state, parameters)), {
      
      Nh <- Sh + Eh + Ih + Rh
      
      dSh <- -(beta * Sh * (Ih/Nh))
      dEh <- (beta * Sh * (Ih/Nh)) - (sigma * Eh)
      dIh <- (sigma * Eh) - (gamma * Ih)
      dRh <- gamma * Ih
      
      return(list(c(dSh, dEh, dIh, dRh), Nh = Nh))
   })
}

# Initial conditions of the population
init <- c(Sh = Sh, Eh = Eh, Ih = Ih, Rh = Rh)
parameters <- c(beta = beta, sigma = sigma, gamma = gamma)
times <- seq(from = 0, to = steps, by = 1)

simulation <- as.data.frame(lsoda(y = init, times = times, func = odeSEIR, parms = parameters))
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