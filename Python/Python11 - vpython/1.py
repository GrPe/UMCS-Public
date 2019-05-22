from vpython import *

scene = canvas()

ball = sphere(pos=vector(-5, 0, 0), radius=0.5, color = color.cyan)
wall = box(pos = vector(6, 0, 0), size = vector(0.2, 12, 12), color = color.green)
wallLeft = box(pos=vector(-6, 0, 0), size=vector(0.2, 12, 12), color = color.yellow)
wallUp = box(pos=vector(0, 6, 0), size=vector(12, 0.2, 12), color = color.red)
wallDown = box(pos=vector(0, -6, 0), size=vector(12, 0.2, 12), color = color.blue)

ball.velocity = vector(25, 18, 0)

deltat = 0.005
t = 0

ball.pos = ball.pos + ball.velocity*deltat


while 1:
    rate(100)
    if ball.pos.x >= wall.pos.x:
        ball.velocity = vector(-ball.velocity.x, ball.velocity.y, 0)
    if ball.pos.x <= wallLeft.pos.x:
        ball.velocity = vector(-ball.velocity.x, ball.velocity.y, 0)
    if(ball.pos.y <= wallDown.pos.y):
        ball.velocity = vector(ball.velocity.x, -ball.velocity.y, 0)
    if(ball.pos.y >= wallUp.pos.y):
        ball.velocity = vector(ball.velocity.x, -ball.velocity.y, 0)
    ball.pos = ball.pos + ball.velocity*deltat
    t = t + deltat