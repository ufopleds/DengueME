
-- Objetive of function UpdateCell2_0:
--
-- Updates the attributes (for cell and humans) related with humans
--
-- 1) Updates cell counters for infected and recovered humans and infected female mosquitos
-- 2) Updates cell attributes to Observer/visualization


function UpdateCell2_0(cell,classesHum)
	-- For the humans' attributes
	-- If all humans in the cell are recovered
	if (cell.NRecoverH == cell[POPULATION_ATTRIBUTE]) then 
		-- Updating the cell states to Observer
		cell.Hstate = "AllRecovereds"; -- this state means that all humans in the cell are recovereds 
		cell.humans_condition = classesHum[cell.Hstate];
		cell.NExposH = 0;
		cell.NInfecH = 0;
	-- If there are infected humans in the cell		
	elseif (cell.NExposH > 0) or (cell.NInfecH > 0) then
		-- Updating the cell states to Observer
		cell.Hstate = "Infecs";
		cell.humans_condition = classesHum[cell.Hstate];
		-- Marking the cell to be accessed in the next dynamical trajectory 
		cell.trajec = 1;
		forEachNeighbor(
			cell,
			function(cell,neighbor)
				neighbor.trajec = 1;
			end
		)
	else 
		-- Updating the cell states to Observer
		cell.Hstate = "SuscNoInfecs";
		cell.humans_condition = classesHum[cell.Hstate];
		cell.NExposH = 0;
		cell.NInfecH = 0;				
	end
	-- For the mosquitoes' attributes
	-- If there are infected female mosquitoes in the cell
	if (cell.NExposFM > 0) or (cell.NInfecFM > 0) then
		-- Updating the cell states to Observer
		cell.FMstate = "Infecs";
		-- Marking the cell to be accessed in the next dynamical trajectory 
		cell.trajec = 1;
	-- If there aren't infected female mosquitoes in the cell
	else	
		-- if there are vectors in the cell and no infected vectors
		if (cell.FMstate ~= "NoFMosqs") then
			-- Updating the cell states to Observer
			cell.FMstate = "SuscNoInfecs";								
		end				
	end		
	return cell			
end