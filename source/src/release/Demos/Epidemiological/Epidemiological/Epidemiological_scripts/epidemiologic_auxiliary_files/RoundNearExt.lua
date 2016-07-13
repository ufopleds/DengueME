-- RoundNearExt function (Extended Round Near Function)
--
-- Rounds the number to the nearest number with specific decimal part
--
-- Inputs:
--
-- number - number to be rounded
-- ndd - number of decimal digits

-- require("workspace.epidemiological.epidemiologic_auxiliary_files.RoundNear")

function RoundNearExt(number,ndd)
	local ntemp = number * math.pow(10,ndd);
	ntemp = RoundNear(ntemp);
	roundedNumber = ntemp/math.pow(10,ndd); 
	return roundedNumber
end


