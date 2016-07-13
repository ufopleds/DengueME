cell = Cell {}
cell.Sh = Nh-1  -- humanos suscetíves
cell.Ih = 1     -- humanos infectados
cell.Rh = 0     -- humanos imunes/recuperados
cell.Sv = Nv    -- vetores suscetíves
cell.Iv = 0     -- vetores infectados

cell:synchronize()

nishiura = function (cell)
    Nh = cell.Sh + cell.Ih + cell.Rh
    Nv = cell.Sv + cell.Iv

    dSh = Mh * (Nh - cell.Sh) - (Bh * b / Nh) * cell.Sh * cell.Iv
    dIh = (Bh * b / Nh) * cell.Sh * cell.Iv - (Mh + y) * cell.Ih
    dRh = y * cell.Ih - Mh * cell.Rh
    dSv = A - (Bv * b / Nh) * cell.Sv * cell.Ih - Mv * cell.Sv
    dIv = (Bv * b / Nh) * cell.Sv * cell.Ih - Mv * cell.Iv

    cell.Sh = cell.Sh + dSh
    cell.Ih = cell.Ih + dIh
    cell.Rh = cell.Rh + dRh
    
    cell.Sv = cell.Sv + dSv
    cell.Iv = cell.Iv + dIv
    
    cell:notify(timer:getTime())
end

nishiuraModel = Event {
    time = 1, period = 1 , priority = 1,
    action  = function (event)
	nishiura(cell)
    end
}

Observer {
    subject = cell,
    attributes = {'Sh', 'Ih', 'Rh'},
    type = 'chart',
    xLabel = '-- Time --',
    yLabel = '-- Values --'
}

timer = Timer {nishiuraModel}
timer:execute(steps)
