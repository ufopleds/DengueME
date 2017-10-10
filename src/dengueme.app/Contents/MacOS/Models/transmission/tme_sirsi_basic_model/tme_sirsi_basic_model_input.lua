-- DengueME Models Library
-- @id tme_sirsi_basic_model
-- @name SIR-SI Basic Model
-- @version 1.0
-- @interpreter TerraME 2.0-RC-4
-- @example A Susceptible-Infected-Recovered-Susceptible-Infected (SIR-SI) basic model.
-- @authors Tiago Lima, Lucas Saraiva
-- @description SIR-SI basic model is a simplified version of the model proposed by Nishiura (2006). For a complete description of such model please see the paper Nishiura (2006), "Mathematical and Statistical Analyses of the Spread of Dengue", Dengue Bulletin, Volume 30, 2006.

-- INPUT FILE
print('LOADING INPUT FILE AND RUNNING MODEL')
io.flush();

-- PATH CONFIG
BASE_PATH = "D:/github/workingpath/DengueMELib/Models/transmission/tme_sirsi_basic_model"
SCRIPT_PATH = "D:/github/workingpath/DengueMELib/Models/transmission/tme_sirsi_basic_model/tme_sirsi_basic_model_scripts"
RESULTS_PATH = BASE_PATH

-- PARAMETERS
Sh = 9999 -- number of susceptible humans [1-999999999]
Ih = 1 -- number of infectious humans [1-999999999]
Rh = 0 --  number of recovered humans [1-999999999]
Nh = 10000 -- total population [1-999999999]
Sv = 20000 -- number of susceptible vectors [1-999999999]
Iv = 0 -- number of infectious vectors [1-999999999]
Nv = 20000 -- total vector population [1-999999999]
biting = 1 -- average number of bites per mosquito per day [0-999]
gamma = 0.167 -- human recovery rate [0-1]
betah = 0.4 -- transmission probability from the vector to human [0-1]
betav = 0.4 -- transmission probability from the human to vector [0-1]


-- SIMULATION
steps = 120 -- simulation steps [0-999999999]

-- RESULTS
outChart = true
outChartSelect = {"Sh", "Ih", "Rh", "Sv", "Iv"}
outChartLabel = {"Susceptible (human)", "Infectious (human)", "Recovered (human)", "Susceptible (vector)", "Infectious (vector)"}
outChartStyle = {"lines", "lines", "lines", "dots", "dots"}
outChartColor = {"blue", "red", "yellow", "blue", "red"}
outChartTitle = ""
outChartXLabel = "Time"
outChartYLabel = ""

outChartHuman = true
outChartHumanSelect = {"Sh", "Ih", "Rh", "Nh"}
outChartHumanLabel = {"Susceptible", "Infectious", "Recovered", "Humam Population"}
outChartHumanStyle = {"lines", "lines", "lines", "dots"}
outChartHumanColor = {"blue", "red", "yellow", "black"}
outChartHumanTitle = ""
outChartHumanXLabel = "Time"
outChartHumanHYLabel = ""

outChartVector = true
outChartVectorSelect = {"Sv", "Iv", "Nv"}
outChartVectorLabel = {"Susceptible", "Infectious", "Vector Population"}
outChartVectorStyle = {"lines", "lines", "dots"}
outChartVectorColor = {"blue", "red", "black"}
outChartVectorTitle = ""
outChartVectorXLabel = "Time"
outChartVectorYLabel = ""

outTextScreen = true
outTextScreenSelect = {"Sh", "Ih", "Rh", "Nh", "Sv", "Iv", "Nv"}

outVisualTable = true
outVisualTableSelect = {"Sh", "Ih", "Rh", "Nh", "Sv", "Iv", "Nv"}

outLog = true
outLogSelect = {"Sh", "Ih", "Rh", "Nh", "Sv", "Iv", "Nv"}
outLogFile = RESULTS_PATH .. "/results.csv"
outLogSeparator = ";"
outLogOverwrite = true

output = outChart or outChartHuman or outChartVector or outTextScreen or outVisualTable or outLog

-- LOADING MODEL
dofile(SCRIPT_PATH .. "/tme_sirsi_basic_model.lua")