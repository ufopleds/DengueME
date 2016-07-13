cell = Cell {}
cell.Sh = Nh-1  -- humanos suscetíves
cell.Eh = 0     -- humanos com o vírus em período de incubação
cell.Ih = 1     -- humanos infectados
cell.Rh = 0     -- humanos imunes/recuperados
cell.Sv = Nv    -- vetores suscetíves
cell.Iv = 0     -- vetores infectados

cell:synchronize()

Observer {
    subject = cell,
    attributes = {'Sh', 'Eh', 'Ih', 'Rh'},
    type = 'chart',
    xLabel = '-- Time --',
    yLabel = '-- Values --'
}

pop_infection = Event {
    time = 1, period = 1 , priority = 1,
    action  = function (event)
--         Mortalidade/Natalidade
        cell.Sh = cell.Sh + Mh * (Nh - cell.past.Sh)
        cell.Ih = cell.Ih - Mh * cell.past.Ih
        cell.Rh = cell.Rh - Mh * cell.past.Rh

        cell.Sv = cell.Sv + A - Mv * cell.past.Sv
        cell.Iv = cell.Iv - Mv * cell.past.Iv

--         Infecção
        dt = (Bh * b / Nh) * cell.past.Sh * cell.past.Iv
        cell.Sh = cell.Sh - dt
        cell.Eh = cell.Eh + dt

        dt = (Bv * b / Nh) * cell.past.Sv * cell.past.Ih
        cell.Sv = cell.Sv - dt
        cell.Iv = cell.Iv + dt

        cell:notify(timer:getTime())
    end
}

incubation = Event {
    time = ip, period = 1 , priority = 1,
    action  = function (event)
        dt = cell.past.Eh / ip
        cell.Eh = cell.Eh - dt
        cell.Ih = cell.Ih + dt
    end
}

recovery = Event {
    time = 1/y, period = 1 , priority = 1,
    action  = function (event)
        dt = y * cell.past.Ih
        cell.Ih = cell.Ih - dt
        cell.Rh = cell.Rh + dt
    cell:synchronize()
    end
}

timer = Timer {pop_infection, incubation, recovery}
timer:execute(steps)

