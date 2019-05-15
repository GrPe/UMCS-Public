import numpy
import random
import matplotlib.pyplot as plt

def getNumber():
    a = random.randint(1, 100)
    if a <= 85:
        return 1
    elif a <= 85+7:
        return 2
    elif a <= 85+7+7:
        return 3
    else:
        return 4


def foo1(x, y):
    return (0.85*x + 0.04*y, -0.04*x + 0.85*y + 1.6)
def foo2(x, y):
    return (-0.15*x + 0.28*y, 0.26*x + 0.24*y + 0.44)
def foo3(x, y):
    return (0.20*x - 0.26*y, 0.23*x + 0.22*y + 1.6)
def foo4(x, y):
    return (0, 0.16*y)

n = 3000
point = (0,0)

for i in range(0, n):
    x = getNumber()
    if x == 1:
        point = foo1(point[0], point[1])
        plt.scatter(point[0], point[1], s=15, c = 'black')
    elif x == 2:
        point = foo2(point[0], point[1])
        plt.scatter(point[0], point[1], s=15, c = 'black')
    elif x == 3:
        point = foo3(point[0], point[1])
        plt.scatter(point[0], point[1], s=15, c = 'black')
    elif x == 4:
        point = foo4(point[0], point[1])
        plt.scatter(point[0], point[1], s=15, c = 'black')

plt.show()
