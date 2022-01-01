local lunikey = require("lunikey")

function love.load()
    c = lunikey.new()
    font = love.graphics.newFont("inter.ttf", 30)
    love.keyboard.setKeyRepeat(true)
end

function love.textinput(key)
    if key == "space" then
        c:process(" ")
    else
        c:process(key)
    end
end

function love.keypressed(key)
    if key == "backspace" then
        c:process_backspace()
    end
end

function love.draw()
    love.graphics.setFont(font)
    love.graphics.print(c:text(), 0, 0)
end