----------------------------------------------------------------------------------------------------------
------- Dengue ABM Model: file to call the auxiliary programs -------
----------------------------------------------------------------------------------------------------------
-- Author: Líliam César de Castro Medeiros, Raian Vargas Maretto
----------------------------------------------------------------------------------------------------------
-- init file

dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/LoadCellSpaceAtt3_2.lua")
dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/InitCond.lua")
dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/DailyNHumRenewal.lua")
dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/UpdateCell.lua")
dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/RoundNear.lua")
dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/RoundProb.lua")
dofile(SCRIPT_PATH .. "/epidemiologic_auxiliary_files/RoundNearExt.lua")

-- END

