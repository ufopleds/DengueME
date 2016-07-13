
-- INITIAL CONDITION: INFECTING A HUMAN ON THE NETWORK --------
function InitCond(cellSpace,typeCond,Ninfecs,Nrecovers,classesHum)
	-- Initializing the counters 
	NDHumI = 0;    -- Daily number of infected humans 
	NDHumR = 0;    -- Daily number of recovered humans
		   	           -- this number is almost cumulative (except for the renewed humans)
	-- if the initial condition is a set of random infected and recovered humans 
	if typeCond == "RandomlyDist" then
		for i = 1,Ninfecs,1 do  -- if Ninfecs=0, this procedure doesn't work
			-- Drafting a random cell in the cellular space
			repeat
				cell = cellSpace:sample();
			until (cell.Hstate ~= "Empty")
			-- Choosing one central cell
			--pos = math.modf(csDim/2); -- this function returns 2 numbers: the first one is the integral part 
        			                    -- of the number and the second is the decimal part of the number 
		
			--coord = Coord{x = pos, y = pos};
			--cell = cellSpace:getCell(coord);                                                      
			-- Drafting a random human agent in the drawn cell
			--table.foreach(cell.humans, print)
			--print(cell.humans:size())
			agentH = cell.humans:sample(); 
			-- Infecting this human
			agentH.state = "I";
			-- Adjusting the time of infection
			agentH.timeOfInfec = math.random(agentH.tToRecover);
			-- Changing the number of infected humans in the cell
			cell.NInfecH = cell.NInfecH + 1;
			NDHumI = NDHumI + 1; 
			-- Adjusting the cell state with relation to humans
			cell.Hstate = "Infecs";
			cell.humans_condition = classesHum[cell.Hstate];	
			-- Marking the cells to be accessed in the dynamical trajectory 
			cell.trajec = 1;
			forEachNeighbor(
				cell,
				function(cell,neighbor)
					neighbor.trajec = 1;
				end
			)
		end	
		for i = 1,Nrecovers,1 do    -- if Nrecovers=0, this procedure doesn't work
			-- Drafting a random cell in the cellular space
			repeat
				cell = cellSpace:sample();
			until (cell.Hstate ~= "Empty")
			-- Drafting a random human agent in the drawn cell
			agentH = cell.humans:sample(); 
			-- Putting recovered state in this human
			agentH.state = "R";
			-- Changing the number of recovereds humans in the cell
			cell.NRecoverH = cell.NRecoverH + 1;
			NDHumR = NDHumR + 1;
			if (cell.NRecoverH == cell[POPULATION_ATTRIBUTE]) then 
				-- Updating the cell states to Observer
				cell.Hstate = "AllRecovereds"; -- this state means that all humans in the cell are recovereds 
				cell.humans_condition = classesHum[cell.Hstate];
				cell.NExposH = 0;
				cell.NInfecH = 0;
			end						
		end			
		-- Initializing the counters 
		NDNHumE = 0;   -- Daily number of new infected-exposed humans
		NDfMosqI = 0;  -- Daily number of infected female mosquitoes
					   -- this number is almost cumulative (except for the renewed female mosquitoes)
		NDNfMosqE = 0; -- Daily number of new infected-exposed female mosquitoes
	
					
		return cellSpace, NDHumI, NDHumR, NDNHumE, NDfMosqI, NDNfMosqE
	end
end		
-----------------------------------------------------------------------------