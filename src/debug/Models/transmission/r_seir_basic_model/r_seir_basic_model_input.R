# DengueME Models Library
# @id r_seir_basic_model
# @name SEIR Basic Model
# @version 1.0
# @interpreter R v3.4.1
# @example A Susceptible-Exposed-Infectious-Recovered (SEIR) basic model
# @authors Fellipe Prado, Tiago Lima
# @description For a description of such model, please visit http://en.wikipedia.org/wiki/Epidemic_model

# INPUT FILE
print('LOADING INPUT FILE AND RUNNING MODEL')

# DEPENDENCIES
MODEL_RVERSION <- "3.4.1"
DEPENDENCIES <- data.frame(lib = c("deSolve"), version = c("1.20"), stringsAsFactors = F)

# PATH CONFIG
DMELIB_PATH <- "D:/github/workingpath/DengueMELib/Models/"
BASE_PATH <- "D:/github/workingpath/DengueMELib/Models/transmission/r_seir_basic_model"
SCRIPT_PATH <- "D:/github/workingpath/DengueMELib/Models/transmission/r_seir_basic_model/r_seir_basic_model_scripts"
RESULTS_PATH <- BASE_PATH

# checking dependencies
USER_RVERSION <- package_version(R.version)
USER_PACKINFO <- installed.packages(fields = c("Package", "Version"))
source(paste0(DMELIB_PATH, "dmelib.r"))
dmelib_check_dependencies(modelRVersion = MODEL_RVERSION, modelDependences = DEPENDENCIES, userRVersion = USER_RVERSION, userLibs = USER_PACKINFO)

# PARAMETERS
Sh <- 9999 # number of susceptible humans [1-999999999]
Eh <- 0 # number of exposed humans [1-999999999]
Ih <- 1 # number of infectious humans [1-999999999]
Rh <- 0 #  number of recovered humans [1-999999999]
Nh <- 10000 # total population
beta <- 1.06 # transmission rate [0-100]
sigma <- 0.07 # exposed to infectious rate [0-1]
gamma <- 0.14 # recovery rate [0-1]

# SIMULATION
steps <- 120 # simulation steps [0-999999999]

# RESULTS
outChart <- TRUE
outChartSelect <- c("Sh", "Eh", "Ih", "Rh")
outChartLabel <- c("Susceptible", "Exposed", "Infectious", "Recovered")
outChartStyle <- c("l", "l", "l", "l")
outChartColor <- c("blue", "orange", "red", "green")
outChartTitle <- ""
outChartXLabel <- "Time"
outChartYLabel <- "Humans"

outTextScreen <- TRUE
outTextScreenSelect <- c("Sh", "Eh", "Ih", "Rh", "Nh")

outVisualTable <- TRUE
outVisualTableSelect <- c("Sh", "Eh", "Ih", "Rh", "Nh")

outLog <- TRUE
outLogSelect <- c("Sh", "Eh", "Ih", "Rh", "Nh")
outLogFile <- paste0(RESULTS_PATH, "/results.csv")
outLogSeparator <- ";"
outLogOverwrite <- TRUE

output <- outChart | outTextScreen | outVisualTable | outLog

# LOADING MODEL
source(paste0(SCRIPT_PATH, "/r_seir_basic_model.r"))