-- @example A Susceptible-Infected-Recovered basic (SIR) model. 
-- @version TerraME 1.6
-- @authors Tiago Lima, Lucas Saraiva
-- @description For a description of such model visit <<http://en.wikipedia.org/wiki/Epidemic_model>>

world = Cell {
    Sh = human_susceptible,
    Ih = human_infected, 
    Rh = human_removed,
    Nh = human_susceptible + human_infected + human_removed,
    Sv = vector_susceptible,
    Iv = vector_infected,
    Nv = vector_susceptible + vector_infected,
    b = vector_bites_rate,      
    gamma = human_recovery_rate,            -- gamma
    Bh = vector_human_transmission_rate,    -- betaH
    Bv = human_vector_transmission_rate     -- betaV
}

chartHuman = Chart { 
    target = world, 
    select = {"Sh", "Ih", "Rh", "Nh"}, 
    color = {"blue", "red", "yellow", "black"}
    }

chartVector = Chart { 
    target = world, 
    select = {"Sv", "Iv", "Nv"}, 
    color = {"blue", "red", "black"}
    }
    
world:notify()

t = Timer {
    Event {
        action = function()
            local new_human_infections = ( world.Bh * world.b / world.Nh ) * world.Sh * world.Iv
            if new_human_infections > world.Sh then
               new_human_infections = world.Sh
            end
            local new_vector_infections = ( world.Bv * world.b / world.Nh ) * world.Sv * world.Ih
            if new_vector_infections > world.Sv then
               new_vector_infections = world.Sv
            end
            world.Rh = world.Rh + (world.gamma * world.Ih)
            world.Ih = world.Ih + new_human_infections - (world.gamma * world.Ih)
            world.Sh = world.Sh - new_human_infections
            world.Nh = world.Sh + world.Ih + world.Rh
            
            world.Iv = world.Iv + new_vector_infections
            world.Sv = world.Sv - new_vector_infections
            world.Nv = world.Sv + world.Iv
            world:notify()
        end
    }
}

t:execute(steps)
print("READY");
io.flush();