-- RoundProb function
--
-- Rounds the number to the interger above with 
-- probability = decimal part of the number
--
-- function call:
-- rounded = RoundProb(number)

-- procedure to ensure the pseudorandom numbers are not fixed 
math.randomseed(os.time())
math.random();

function RoundProb(number)
	local IntergerPart, FracPart = math.modf(number);
	if (math.random() <= FracPart) then
		roundedNumber = IntergerPart + 1;
	else
		roundedNumber = IntergerPart;
	end
	return roundedNumber
end
