# DengueME Models Library
# @id r_sirsi_basic_model
# @name SIR-SI Basic Model
# @version 1.0
# @interpreter R v3.4.1
# @example A Susceptible-Infected-Recovered-Susceptible-Infected (SIR-SI) basic model.
# @authors Fellipe Prado, Tiago Lima
# @description SIR-SI basic model is a simplified version of the model proposed by Nishiura (2006). For a complete description of such model please see the paper Nishiura (2006), "Mathematical and Statistical Analyses of the Spread of Dengue", Dengue Bulletin, Volume 30, 2006.

# INPUT FILE
print('LOADING INPUT FILE AND RUNNING MODEL')

# DEPENDENCIES
MODEL_RVERSION <- "3.4.1"
DEPENDENCIES <- data.frame(lib = c("deSolve"), version = c("1.20"), stringsAsFactors = F)

# PATH CONFIG
DMELIB_PATH <- "D:/github/workingpath/DengueMELib/Models/"
BASE_PATH <- "D:/github/workingpath/DengueMELib/Models/transmission/r_sirsi_basic_model"
SCRIPT_PATH <- "D:/github/workingpath/DengueMELib/Models/transmission/r_sirsi_basic_model/r_sirsi_basic_model_scripts"
RESULTS_PATH <- BASE_PATH

# checking dependencies
USER_RVERSION <- package_version(R.version)
USER_PACKINFO <- installed.packages(fields = c("Package", "Version"))
source(paste0(DMELIB_PATH, "dmelib.r"))
dmelib_check_dependencies(modelRVersion = MODEL_RVERSION, modelDependences = DEPENDENCIES, userRVersion = USER_RVERSION, userLibs = USER_PACKINFO)

# PARAMETERS
Sh <- 9999 # number of susceptible humans [1-999999999]
Ih <- 1 # number of infectious humans [1-999999999]
Rh <- 0 #  number of recovered humans [1-999999999]
Nh <- 10000 # total population [1-999999999]
Sv <- 20000 # number of susceptible vectors [1-999999999]
Iv <- 0 # number of infectious vectors [1-999999999]
Nv <- 20000 # total vector population [1-999999999]
bitting <- 1 # average number of bites per mosquito per day [0-999]
gamma <- 0.167 # human recovery rate [0-1]
betah <- 0.4 # transmission probability from the vector to human [0-1]
betav <- 0.4 # transmission probability from the human to vector [0-1]


# SIMULATION
steps <- 120 # simulation steps [0-999999999]

# RESULTS
outChartHuman <- TRUE
outChartHumanSelect <- c("Sh", "Ih", "Rh")
outChartHumanLabel <- c("Susceptible", "Infectious", "Recovered")
outChartHumanStyle <- c("l", "l", "l")
outChartHumanColor <- c("blue", "red", "green")
outChartHumanTitle <- ""
outChartHumanXLabel <- "Time"
outChartHumanHYLabel <- ""

outChartVector <- TRUE
outChartVectorSelect <- c("Sv", "Iv")
outChartVectorLabel <- c("Susceptible", "Infectious")
outChartVectorStyle <- c("l", "l")
outChartVectorColor <- c("blue", "red")
outChartVectorTitle <- ""
outChartVectorXLabel <- "Time"
outChartVectorYLabel <- ""

outTextScreen <- TRUE
outTextScreenSelect <- c("Sh", "Ih", "Rh", "Nh", "Sv", "Iv", "Nv")

outVisualTable <- TRUE
outVisualTableSelect <- c("Sh", "Ih", "Rh", "Nh", "Sv", "Iv", "Nv")

outLog <- TRUE
outLogSelect <- c("Sh", "Ih", "Rh", "Nh", "Sv", "Iv", "Nv")
outLogFile <- paste0(RESULTS_PATH, "/results.csv")
outLogSeparator <- ";"
outLogOverwrite <- TRUE

output <- outChartHuman | outChartVector | outTextScreen | outVisualTable | outLog

# LOADING MODEL
source(paste0(SCRIPT_PATH, "\\r_sirsi_basic_model.r"))