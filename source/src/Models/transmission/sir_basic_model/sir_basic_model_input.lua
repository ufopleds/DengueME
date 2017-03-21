-- DengueME Models Library
-- @id sir_basic_model
-- @name SIR Basic Model
-- @version 1.0
-- @interpreter TerraME 2.0-beta4
-- @example A Susceptible-Infected-Recovered basic (SIR) model. 
-- @authors Tiago Lima, Lucas Saraiva
-- @description For a description of such model visit <<http://en.wikipedia.org/wiki/Epidemic_model>>

-- INPUT FILE

print('LOADING INPUT FILE AND RUNNING MODEL')
io.flush();

-- PATH CONFIG
BASE_PATH = "D:/github/workingpath/DengueMELib/Models/transmission/sir_basic_model"
SCRIPT_PATH = "D:/github/workingpath/DengueMELib/Models/transmission/sir_basic_model/sir_basic_model_scripts"
RESULTS_PATH = BASE_PATH

-- PARAMETERS
Sh = 9999 -- number of susceptible humans [1-999999999]
Ih = 1 -- number of infected humans [1-999999999]
Rh = 0 --  number of recovered humans [1-999999999]
Nh = 10000 -- total population
beta = 1.06 -- infection rate [0-100]
gamma = 0.25 -- recovery rate [0-1]

-- SIMULATION
steps = 120 -- simulation steps [0-999999999]

-- RESULTS
outChart = true
outChartSelect = {"Sh", "Ih", "Rh", "Nh"}
outChartLabel = {"Susceptible", "Infected", "Recovered", "Humam Population"}
outChartStyle = {"lines", "lines", "lines", "dots"}
outChartColor = {"blue", "red", "yellow", "black"}
outChartTitle = ""
outChartXLabel = "Time"
outChartYLabel = ""

outTextScreen = true
outTextScreenSelect = {"Sh", "Ih", "Rh"}

outVisualTable = true
outVisualTableSelect = {"Sh", "Ih", "Rh"}

outLog = true
outLogSelect = {"Sh", "Ih", "Rh", "Nh"}
outLogFile = RESULTS_PATH .. "/results.csv"
outLogSeparator = ";"
outLogOverwrite = true

output = outChart or outTextScreen or outVisualTable or outLog

-- LOADING MODEL
dofile(SCRIPT_PATH .. "/sir_basic_model.lua")
