import numpy
import random
import matplotlib.pyplot as plt
import math
from decimal import Decimal


def foo(x, n, c):
    res = x
    for i in range(1, n):
        res = res*res +c
    return res

n = 550
c = -0.1 + 0.65j
complexity = 1000

for x in numpy.linspace(-2.0, 2.0, num=complexity):
    for y in numpy.linspace(-2.0, 2.0, num=complexity):
        if(abs(foo(complex(x, y),n, c)) < 2):
            plt.scatter(x, y, s=1, c='black')

plt.show()
