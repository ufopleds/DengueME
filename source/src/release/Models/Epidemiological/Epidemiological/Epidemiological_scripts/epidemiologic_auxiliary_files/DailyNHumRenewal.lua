
-- DailyNHumRenewal(cellSpace,DailyHRenewal) renewals DailyHRenewal humans at the current day
--
-- Since DailyHRenewal isn't a interger number, its decimal part becomes a probability to add 
-- a new human to the interger part
--
-- This program is located before the Update Module. So, if the attribute cell.trajec = 0, 
-- the new human can replace a recovered one
 

function DailyNHumRenewal(cellSpace,DailyHRenewal,NDHumR)
	-- Calculating the number of humans to be renewed
	local TodayNHRenewal = RoundProb(DailyHRenewal);
	for i = 1,TodayNHRenewal,1 do
		-- Drafting an occuped cell in the cell space
		repeat
			cell = cellSpace:sample();
		until (cell.Hstate ~= "Empty")
		-- Drafting a random human agent in the drawn cell
		agentH = cell.humans:sample();
		-- if this human is recovered				
		if (agentH.state == "R") then
			-- The cumulative number of recovered dacays
			NDHumR = NDHumR - 1;
			cell.NRecoverH = cell.NRecoverH - 1;
			-- Send the cell to trajectory to recount its attributes in the Update Module (next step in main program)
			cell.past.trajec = 1;
		elseif (agentH.state == "I") then
			cell.NInfecH = cell.NInfecH - 1; 
			-- Send the cell to trajectory to recount its attributes in the Update Module (next step in main program)
			cell.past.trajec = 1;
		elseif (agentH.state == "E") then
			cell.NExposH = cell.NExposH - 1; 
			-- Send the cell to trajectory to recount its attributes in the Update Module (next step in main program)
			cell.past.trajec = 1;
		end		
		-- Setting the attributes of the new human (considering he is susceptible)
		agentH.state = "S";
		agentH.IncPer = 5;
		agentH.tToRecover = 5;
		agentH.timeOfInfec = 0;		
	end
	return cellSpace, NDHumR
end