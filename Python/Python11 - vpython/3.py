# y = Asin(wt)
from vpython import *

floor = box (pos=vector(0,0,0), length=4, height=0.5, width=4, color=color.blue)
ball = sphere (pos=vector(0,4,0), radius=0.3, color=color.red)
spring = helix(pos = vector(0,4,0), axis=vector(0, 4, 0), radius = 0.5)
ball.velocity = vector(0,0,0)
dt = 0.01

while 1:
    rate (200)
    ball.pos = ball.pos + ball.velocity*dt
    spring.axis = ball.pos-spring.pos
    if ball.pos.y < ball.radius:
        ball.velocity.y = abs(ball.velocity.y)
    else:
        ball.velocity.y = ball.velocity.y - 9.8*dt