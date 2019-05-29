from vpython import *

def distance(v1, v2):
    return sqrt((v2.x-v1.x)**2 + (v2.y - v1.y)**2)

scene = canvas()

r = 2


wall = box(pos = vector(24, 0, 0), size = vector(0.2, 48, 48), color = color.green)
wallLeft = box(pos=vector(-24, 0, 0), size=vector(0.2, 48, 48), color = color.yellow)
wallUp = box(pos=vector(0, 24, 0), size=vector(48, 0.2, 48), color = color.red)
wallDown = box(pos=vector(0, -24, 0), size=vector(48, 0.2, 48), color = color.blue)


balls = [
sphere(pos = vector(0,0,0),radius = r),
sphere(pos = vector(-15, -15, 0),radius = r),
sphere(pos = vector(10, 10, 0),radius = r),
sphere(pos = vector(-6, 14, 0),radius = r),
sphere(pos = vector(-4, 2, 0),radius = r),
sphere(pos = vector(7, 5, 0),radius = r)]

balls[0].velocity = vector(-3,-3,0)
balls[1].velocity = vector(3, 4, 0)
balls[2].velocity = vector(0, 4, 0)
balls[3].velocity = vector(0, 2, 0)
balls[4].velocity = vector(-3, 12, 0)
balls[5].velocity = vector(10, 12, 0)
dt = 0.01



while 1:
    rate(500)

    for x in balls:
        x.pos = x.pos + x.velocity*dt

    for i in range (len(balls)):
        for j in range(i + 1, len(balls)):
            if distance(balls[i].pos, balls[j].pos) - 2*r < 0.002:
                v1, v2 = balls[i].velocity, balls[j].velocity
                balls[i].velocity -= (balls[j].pos - balls[i].pos)*(mag(v1)/(mag(v1)+mag(v2)))
                balls[j].velocity -= (balls[i].pos - balls[j].pos)*(mag(v2)/(mag(v1)+mag(v2)))

    for ball in balls:
        if ball.pos.x + r >= wall.pos.x:
            ball.velocity = vector(-ball.velocity.x, ball.velocity.y, 0)
        if ball.pos.x - r <= wallLeft.pos.x:
            ball.velocity = vector(-ball.velocity.x, ball.velocity.y, 0)
        if(ball.pos.y - r <= wallDown.pos.y):
            ball.velocity = vector(ball.velocity.x, -ball.velocity.y, 0)
        if(ball.pos.y + r >= wallUp.pos.y):
            ball.velocity = vector(ball.velocity.x, -ball.velocity.y, 0)