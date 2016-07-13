-- @example A Susceptible-Infected-Recovered basic (SIR) model. 
-- @version TerraME 1.6
-- @authors Tiago Lima, Lucas Saraiva
-- @description For a description of such model visit <<http://en.wikipedia.org/wiki/Epidemic_model>>

world = Cell {
    Sh = susceptible,
    Ih = infected, 
    Rh = recovered,
    Nh = susceptible + infected + recovered,
    beta = infection_rate,
    gamma = recovery_rate
}

chart = Chart { 
    target = world, 
    select = {"Sh", "Ih", "Rh", "Nh"}, 
    color = {"blue", "red", "yellow", "black"}
    }

world:notify()

t = Timer {
    Event {
        action = function()
            local new_infections = world.beta * ( world.Sh * world.Ih / world.Nh )    -- beta = infection_rate
            if new_infections > world.Sh then
               new_infections = world.Sh
            end
            world.Rh = world.Rh + (world.gamma * world.Ih)
            world.Ih = world.Ih + new_infections - (world.gamma * world.Ih)
            world.Sh = world.Sh - new_infections
            world.Nh = world.Sh + world.Ih + world.Rh
            world:notify()
        end
    }
}

t:execute(steps)