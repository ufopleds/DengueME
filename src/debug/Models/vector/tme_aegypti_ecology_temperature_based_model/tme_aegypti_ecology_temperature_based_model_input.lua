-- DengueME Models Library
-- @id tme_aegypti_ecology_temperature_based_model
-- @name Temperature-based vector ecology model
-- @version 1.0
-- @interpreter TerraME 2.0-RC-4
-- @example Temperature-based model of Aedes aegypti ecology
-- @authors Raquel Lana, Tiago Carneiro, Cláudia Codeço, Tiago Lima
-- @description An Aedes aegypti population model with four compartments representing (egg, larva, pupa and adult) with temperature-dependent transition rates. For a complete description of such model please see the paper Lana et al. (2014), "Seasonal and nonseasonal dynamics of Aedes aegypti in Rio de Janeiro, Brazil: Fitting mathematical models to trap data", Acta Tropica, Volume 129, 2014.

-- INPUT FILE
print('LOADING INPUT FILE AND RUNNING MODEL')
io.flush();

-- PATH CONFIG
BASE_PATH = "D:/github/workingpath/DengueMELib/Models/vector/tme_aegypti_ecology_temperature_based_model"
SCRIPT_PATH = "D:/github/workingpath/DengueMELib/Models/vector/tme_aegypti_ecology_temperature_based_model/tme_aegypti_ecology_temperature_based_model_scripts"
RESULTS_PATH = BASE_PATH

-- PARAMETERS
eggs = 1000 -- initial value of eggs [1-999999999]
larvae = 0 -- initial value of larvae [1-999999999]
pupae = 0 -- initial value of pupae [1-999999999]
adults = 0 -- initial value of adults [1-999999999]
carrying_cap = 191.5 -- carrying capacity (limits the oviposition) [0-9999999]
oviposition_rate = 1 -- oviposition rate (per day per mosquito) [0-9999999]
-- weekly temperature values
weeklyTemperature = { 23.47142857,22.71428571,24.87142857,26.35714286,22.61428571,25.01428571,26.12857143,21.92857143,26.94285714,26.9,26.28571429,25.52857143,28.6,30.31428571,26.7,26.37142857,25.88571429,26.82857143,28.85714286,27.58571429,29.12857143,27.81428571,29.55714286,29.7,30.21428571,29.58571429,28.18571429,29.35714286,28.18571429,27.54285714,27.11428571,27.38571429,26.07142857,23.71428571,24.78571429,22.02857143,20.95714286,22.91428571,25.18571429,23.75714286,22.67142857,25.15714286,21.65714286,21.08571429,17.98571429,21.45714286,23.01428571,21.68571429,23.95714286,22.7,25.85714286,24.97142857,24.78571429,22.48571429,24.14285714,25.62857143,24.95714286,25.28571429,27.7,26.15714286,24.01428571,25.37142857,24.25714286,28.21428571,26.8,25.57142857,31.18571429,28.91428571,28.98571429,28.15714286,23.71428571,25.17142857,26.98571429,28.88571429,27.8,28.12727273 }
u_eggs = 1/100 -- daily mortality rate in egg stage [0-1]
u_larvae = 1/3 -- daily mortality rate in larval stage [0-1]
u_pupae = 1/70 -- daily mortality rate in pupal stage [0-1]
u_adults = 1/17.5 -- daily mortality rate in adult stage [0-1]
edo_dt = 1 -- a number with the beginning of the interval (EDO function)
edo_upper = 7 -- a number with the end of the interval (EDO function)
edo_delta = 0.1 -- a positive number with the step within the interval (EDO function)

-- SIMULATION
steps = 720 -- simulation steps [0-999999999]

-- RESULTS
outChart = true
outChartSelect = {"eggs", "larvae", "pupae", "adults", "population"}
outChartLabel = {"eggs", "larvae", "pupae", "adults", "population"}
outChartStyle = {"lines", "lines", "lines", "lines", "lines"}
outChartColor = {"blue", "red", "yellow", "black", "gray"}
outChartTitle = ""
outChartXLabel = "Time"
outChartYLabel = ""

outTextScreen = true
outTextScreenSelect = {"eggs", "larvae", "pupae", "adults", "population"}

outVisualTable = true
outVisualTableSelect = {"eggs", "larvae", "pupae", "adults", "population"}

outLog = true
outLogSelect = {"temperature", "eggs", "larvae", "pupae", "adults", "population"} 
outLogFile = RESULTS_PATH .. "/results.csv"
outLogSeparator = ";"
outLogOverwrite = true

output = outChart or outTextScreen or outVisualTable or outLog

-- LOADING MODEL
dofile(SCRIPT_PATH .. "/tme_aegypti_ecology_temperature_based_model.lua")