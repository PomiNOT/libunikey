local lunikey = require("lunikey")

function love.load()
    c = lunikey.new()
    font = love.graphics.newFont("inter.ttf", 30)
    love.keyboard.setKeyRepeat(true)
end

function love.textinput(key)
    if key == "space" then
        lunikey.process(c, " ")
    else
        lunikey.process(c, key)
    end
end

function love.keypressed(key)
    if key == "backspace" then
        lunikey.process_backspace(c)
    end
end

function love.draw()
    love.graphics.setFont(font)
    love.graphics.print(lunikey.get_result(c), 0, 0)
end