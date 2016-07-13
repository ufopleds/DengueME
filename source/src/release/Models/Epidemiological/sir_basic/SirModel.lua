-- @example A Susceptible-Infected-Recovered (SIR) model. In this model
-- the disease has a duration of 8 weeks.
-- @image sir-improved.bmp



world = Cell{
	susceptible = 9998,
	infected = 8,
	recovered = 2
	
}

chart = Chart{target = world}

world:notify()

t = Timer{
	Event{action = function()
		world.recovered = world.recovered + world.infected / duration
		local new_infected = world.infected * contacts * infections * world.susceptible / 10000
		if new_infected > world.susceptible then
			new_infected = world.susceptible
		end
		world.infected = world.infected - world.infected / duration + new_infected
		world.susceptible = 10000 - world.infected - world.recovered
		world:notify()
	end}
}

t:execute(steps)

