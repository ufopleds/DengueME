-- RoundNear function
--
-- Rounds the number to the nearest interger


function RoundNear(number)
	local IntergerPart, FracPart = math.modf(number);
	if (FracPart < 0.5) then
		roundedNumber = IntergerPart;
	else
		roundedNumber = IntergerPart + 1;
	end
	return roundedNumber
end

