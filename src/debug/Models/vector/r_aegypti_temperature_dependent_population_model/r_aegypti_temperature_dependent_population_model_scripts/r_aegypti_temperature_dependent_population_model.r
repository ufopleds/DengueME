# DengueME Models Library
# @id r_aegypti_temperature_dependent_population_model
# @name Aedes aegypti temperature-dependent population model
# @version 1.0
# @interpreter R v3.4.1
# @example Temperature-based model of Aedes aegypti ecology
# @authors Raquel Lana, Cláudia Codeço, Tiago Lima
# @description A population model of the Aedes aegypti vector, with four compartments to represent each of the mosquito life cycle stages (egg, larva, pupa and adult) and temperature-dependent transition rates. For a complete description of such model please see the paper Lana et al. (2014), "Seasonal and nonseasonal dynamics of Aedes aegypti in Rio de Janeiro, Brazil: Fitting mathematical models to trap data", Acta Tropica, Volume 129, 2014.

# DEPENDENCIES
library('deSolve')

################################
# CONSTANTS (MODEL PARAMETERS) 
################################

# Parameters used by thermodynamic equation
R <- 1.98 # universal gas constant

# Development rates: kinetics function models (see Sharpe and DeMichele (1977), Schoofield et al. (1981) and Focks et al. (1993a))
TabEntalpia <- t(matrix(
   c(0.24,10798,100000,14184,    0.2088,26018,55990,304.6,    0.384,14931,-472379,148,    0.216,15725,1756481,447.2,    0.372,15725,1756481,447.2),
   nrow=4,
   ncol=5   
))

# ODE function
odeAedesEcology <- function(t, state, parameters){
   
   if( t == 0) idxTab <- 0 else idxTab <- ceiling(t)
   idxTab <- 1 + (idxTab %% length(weeklyTemperature))   
   
   temp <- weeklyTemperature[idxTab] + 273.15
   
   # Thermodynamic Equation proposed by Sharpe and DeMichelle (1977)
   txTransO <- TabEntalpia[1,1]*((temp/298)*exp((TabEntalpia[1,2]/R)*(1/298 - 1/temp))/(1 + exp((TabEntalpia[1,3]/R)*(1/TabEntalpia[1,4]-1/temp))))
   txTransL <- TabEntalpia[2,1]*((temp/298)*exp((TabEntalpia[2,2]/R)*(1/298 - 1/temp))/(1 + exp((TabEntalpia[2,3]/R)*(1/TabEntalpia[2,4]-1/temp))));
   txTransP <- TabEntalpia[3,1]*((temp/298)*exp((TabEntalpia[3,2]/R)*(1/298 - 1/temp))/(1 + exp((TabEntalpia[3,3]/R)*(1/TabEntalpia[3,4]-1/temp))));
   if ( weeklyTemperature[idxTab] < 4.85 || weeklyTemperature[idxTab] > 33) {
      txTransO <- 0
      txTransL <- 0
      txTransP <- 0
   }
   
   with(as.list(c(state,parameters)), {    ##Lista as variaveis de estado
   
      dEggs <- oviposition_rate * adults * (1-(eggs/carrying_cap)) - (txTransO * eggs + u_eggs * eggs)
      dLarvae <- txTransO * eggs - (txTransL * larvae + u_larvae * larvae)
      dPupae <- txTransL * larvae - (txTransP * pupae + u_pupae * pupae)
      dAdults <- txTransP * pupae - (u_adults * adults)
      
      return(list(c(dEggs, dLarvae, dPupae, dAdults), population = eggs+larvae+pupae+adults, temperature = temp))
   })
   
}

# Initial conditions of the population
init <- c(eggs = eggs, larvae = larvae, pupae = pupae, adults = adults)
# Parameters
parameters <- c(oviposition_rate = oviposition_rate, carrying_cap = carrying_cap, u_eggs = u_eggs, u_larvae = u_larvae, u_pupae = u_pupae, u_adults = u_adults)
# Simulation time
times <- seq(from = 0, to = steps, by = 1)

simulation <- as.data.frame(lsoda(y = init, times = times, func = odeAedesEcology, parms = parameters))

# Results
if (output) {
   if (outChart & length(outChartSelect) > 0) {
      plot(x = simulation$time, y = simulation[,c(outChartSelect[1])], type = outChartStyle[1], col=outChartColor[1], xlab="Time", ylab = "Aedes aegypti", ylim = c(0,600))
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
      write.table(x = simulation[ c("time", outLogSelect) ], file = outLogFile, append = !outLogOverwrite, quote = FALSE, sep = outLogSeparator, col.names = TRUE, row.names = FALSE)
}