# DengueME Models Library
# @id r_aegypti_temperature_dependent_population_model
# @name Aedes aegypti temperature-dependent population model
# @version 1.0
# @interpreter R v3.4.1
# @example Temperature-based model of Aedes aegypti ecology
# @authors Raquel Lana, Cláudia Codeço, Tiago Lima
# @description A population model of the Aedes aegypti vector, with four compartments to represent each of the mosquito life cycle stages (egg, larva, pupa and adult) and temperature-dependent transition rates. For a complete description of such model please see the paper Lana et al. (2014), "Seasonal and nonseasonal dynamics of Aedes aegypti in Rio de Janeiro, Brazil: Fitting mathematical models to trap data", Acta Tropica, Volume 129, 2014.

# INPUT FILE
print('LOADING INPUT FILE AND RUNNING MODEL')

# DEPENDENCIES
MODEL_RVERSION <- "3.4.1"
DEPENDENCIES <- data.frame(lib = c("deSolve"), version = c("1.20"), stringsAsFactors = F)

# PATH CONFIG
DMELIB_PATH <- "D:/github/workingpath/DengueMELib/Models/"
BASE_PATH <- "D:/github/workingpath/DengueMELib/Models/vector/r_aegypti_temperature_dependent_population_model"
SCRIPT_PATH <- "D:/github/workingpath/DengueMELib/Models/vector/r_aegypti_temperature_dependent_population_model/r_aegypti_temperature_dependent_population_model_scripts"
RESULTS_PATH <- BASE_PATH

# checking dependencies
USER_RVERSION <- package_version(R.version)
USER_PACKINFO <- installed.packages(fields = c("Package", "Version"))
source(paste0(DMELIB_PATH, "dmelib.r"))
dmelib_check_dependencies(modelRVersion = MODEL_RVERSION, modelDependences = DEPENDENCIES, userRVersion = USER_RVERSION, userLibs = USER_PACKINFO)

# PARAMETERS
eggs <- 1000 # initial value of eggs [1-999999999]
larvae <- 0 # initial value of larvae [1-999999999]
pupae <- 0 # initial value of pupae [1-999999999]
adults <- 0 # initial value of adults [1-999999999]
carrying_cap <- 191 # carrying capacity (limits the oviposition) [0-9999999]
oviposition_rate <- 1 # oviposition rate (per day per mosquito) [0-9999999]
# weekly temperature values
weeklyTemperature <- c(23.47142857,22.71428571,24.87142857,26.35714286,22.61428571,25.01428571,26.12857143,21.92857143,26.94285714,26.9,26.28571429,25.52857143,28.6,30.31428571,26.7,26.37142857,25.88571429,26.82857143,28.85714286,27.58571429,29.12857143,27.81428571,29.55714286,29.7,30.21428571,29.58571429,28.18571429,29.35714286,28.18571429,27.54285714,27.11428571,27.38571429,26.07142857,23.71428571,24.78571429,22.02857143,20.95714286,22.91428571,25.18571429,23.75714286,22.67142857,25.15714286,21.65714286,21.08571429,17.98571429,21.45714286,23.01428571,21.68571429,23.95714286,22.7,25.85714286,24.97142857,24.78571429,22.48571429,24.14285714,25.62857143,24.95714286,25.28571429,27.7,26.15714286,24.01428571,25.37142857,24.25714286,28.21428571,26.8,25.57142857,31.18571429,28.91428571,28.98571429,28.15714286,23.71428571,25.17142857,26.98571429,28.88571429,27.8,28.12727273)
u_eggs <- 1/100 # daily mortality rate in egg stage [0-1]
u_larvae <- 1/3 # daily mortality rate in larval stage [0-1]
u_pupae <- 1/70 # daily mortality rate in pupal stage [0-1]
u_adults <- 1/17.5 # daily mortality rate in adult stage [0-1]

# SIMULATION
steps <- 720 # simulation steps [0-999999999]

# RESULTS
outChart <- TRUE
outChartSelect <- c("eggs", "larvae", "pupae", "adults", "population")
outChartLabel <- c("Eggs", "Larvae", "Pupae", "Adults", "Vector Population")
outChartStyle <- c("l", "l", "l", "l", "l")
outChartColor <- c("red", "green", "blue", "black", "gray")
outChartTitle <- ""
outChartXLabel <- "Time"
outChartYLabel <- ""

outTextScreen <- TRUE
outTextScreenSelect <- c("eggs", "larvae", "pupae", "adults", "population")

outVisualTable <- TRUE
outVisualTableSelect <- c("eggs", "larvae", "pupae", "adults", "population")

outLog <- TRUE
outLogSelect <- c("temperature", "eggs", "larvae", "pupae", "adults", "population")
outLogFile <- paste0(RESULTS_PATH, "/results.csv")
outLogSeparator <- ";"
outLogOverwrite <- TRUE

output <- outChart | outTextScreen | outVisualTable | outLog

# LOADING MODEL
source(paste0(SCRIPT_PATH, "/r_aegypti_temperature_dependent_population_model.r"))