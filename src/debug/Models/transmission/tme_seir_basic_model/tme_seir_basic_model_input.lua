-- DengueME Models Library
-- @id tme_seir_basic_model
-- @name SEIR Basic Model
-- @version 1.0
-- @interpreter TerraME 2.0-RC-4
-- @example A Susceptible-Exposed-Infectious-Recovered (SEIR) basic model
-- @authors Fellipe Prado, Tiago Lima
-- @description For a description of such model, please visit http://en.wikipedia.org/wiki/Epidemic_model

-- INPUT FILE
print('LOADING INPUT FILE AND RUNNING MODEL')
io.flush();

-- PATH CONFIG
BASE_PATH = "D:/github/workingpath/DengueMELib/Models/transmission/tme_seir_basic_model"
SCRIPT_PATH = "D:/github/workingpath/DengueMELib/Models/transmission/tme_seir_basic_model/tme_seir_basic_model_scripts"
RESULTS_PATH = BASE_PATH

-- PARAMETERS
Sh = 9999 -- number of susceptible humans [1-999999999]
Eh = 0 -- number of exposed humans [1-999999999]
Ih = 1 -- number of infectious humans [1-999999999]
Rh = 0 --  number of recovered humans [1-999999999]
Nh = 10000 -- total population
beta = 1.06 -- transmission rate [0-100]
sigma = 0.07 -- exposed to infectious rate [0-1]
gamma = 0.14 -- recovery rate [0-1]

-- SIMULATION
steps = 120 -- simulation steps [0-999999999]

-- RESULTS
outChart = true
outChartSelect = {"Sh", "Eh", "Ih", "Rh", "Nh"}
outChartLabel = {"Susceptible", "Exposed", "Infectious", "Recovered", "Humam Population"}
outChartStyle = {"lines", "lines", "lines", "lines", "dots"}
outChartColor = {"blue", "orange", "red", "yellow", "black"}
outChartTitle = ""
outChartXLabel = "Time"
outChartYLabel = ""

outTextScreen = true
outTextScreenSelect = {"Sh", "Eh", "Ih", "Rh", "Nh"}

outVisualTable = true
outVisualTableSelect = {"Sh", "Eh", "Ih", "Rh", "Nh"}

outLog = true
outLogSelect = {"Sh", "Eh", "Ih", "Rh", "Nh"}
outLogFile = RESULTS_PATH .. "/results.csv"
outLogSeparator = ";"
outLogOverwrite = true

output = outChart or outTextScreen or outVisualTable or outLog

-- LOADING MODEL
dofile(SCRIPT_PATH .. "/tme_seir_basic_model.lua")