# DengueME Models Library
# @id r_sirsi_basic_model
# @name SIR-SI Basic Model
# @version 1.0
# @interpreter R v3.4.1
# @example A Susceptible-Infected-Recovered-Susceptible-Infected (SIR-SI) basic model.
# @authors Fellipe Prado, Tiago Lima
# @description SIR-SI basic model is a simplified version of the model proposed by Nishiura (2006). For a complete description of such model please see the paper Nishiura (2006), "Mathematical and Statistical Analyses of the Spread of Dengue", Dengue Bulletin, Volume 30, 2006.

# DEPENDENCIES
library('deSolve')

# ODE SIR-SI function
odeSIRSI <- function(times, state, parameters) {

   with(as.list(c(state, parameters)), {
      
      Nh <- Sh + Ih + Rh
      
      dSh <-  (-(betah * bitting)/Nh) * (Sh * Iv)
      dIh <-  ((betah * bitting)/Nh) * (Sh * Iv) - (gamma * Ih)
      dRh <-  (gamma * Ih)
      
      Nv <- Sv + Iv
      
      dSv <-  (-((betav * bitting)/Nh) * (Sv * Ih))
      dIv <-  (((betav * bitting)/Nh) * (Sv * Ih))
      
      return(list(c(dSh, dIh, dRh, dSv, dIv), Nh = Nh, Nv = Nv))
   })
}

# Initial conditions of the population
init <- c(Sh = Sh, Ih = Ih, Rh = Rh, Sv = Sv, Iv = Iv)
parameters <- c(betah = betah, betav = betav, gamma = gamma, bitting = bitting)
times <- seq(from = 0, to = steps, by = 1)

simulation <- as.data.frame(lsoda(y = init, times = times, func = odeSIRSI, parms = parameters))
head(simulation)
tail(simulation)

# Results
if (output) {
   if (outChartHuman & length(outChartHumanSelect) > 0) {
      dev.new()
      plot(x = simulation$time, y = simulation[,c(outChartHumanSelect[1])], type = outChartHumanStyle[1], col=outChartHumanColor[1], xlab="Time", ylab = "Humans")
      if (length(outChartHumanSelect) >= 2)
         for (i in 2:length(outChartHumanSelect))
            lines(x = simulation$time, simulation[,c(outChartHumanSelect[i])], type = outChartHumanStyle[i], col=outChartHumanColor[i])
   }
   if(outChartVector & length(outChartVectorSelect) > 0) {
      dev.new()
      plot(x = simulation$time, y = simulation[,c(outChartVectorSelect[1])], type = outChartVectorStyle[1], col=outChartVectorColor[1], xlab="Time", ylab = "Vectors")
      if (length(outChartVectorSelect) >= 2)
         for (i in 2:length(outChartVectorSelect))
            lines(x = simulation$time, simulation[,c(outChartVectorSelect[i])], type = outChartVectorStyle[i], col=outChartVectorColor[i])
   }
   if (outChartHuman & length(outChartHumanSelect) > 0 & outChartVector & length(outChartVectorSelect) > 0) {
      dev.new()
      par(mfrow=c(2,1))
      plot(x = simulation$time, y = simulation[,c(outChartHumanSelect[1])], type = outChartHumanStyle[1], col=outChartHumanColor[1], xlab="Time", ylab = "Humans")
      if (length(outChartHumanSelect) >= 2)
         for (i in 2:length(outChartHumanSelect))
            lines(x = simulation$time, simulation[,c(outChartHumanSelect[i])], type = outChartHumanStyle[i], col=outChartHumanColor[i])
      plot(x = simulation$time, y = simulation[,c(outChartVectorSelect[1])], type = outChartVectorStyle[1], col=outChartVectorColor[1], xlab="Time", ylab = "Vectors")
      if (length(outChartVectorSelect) >= 2)
         for (i in 2:length(outChartVectorSelect))
            lines(x = simulation$time, simulation[,c(outChartVectorSelect[i])], type = outChartVectorStyle[i], col=outChartVectorColor[i])
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