#!/usr/bin/env python

import cmath

# ax^2 + bx + c = 0

a = float(input())
b = float(input())
c = float(input())

if a == 0:
    print("Incorrect parametr!")
    quit()

delta = b**2 - 4*a*c

if delta > 0:
    x1 = (-b - math.sqrt(delta)) / (2 * a)
    x2 = (-b + math.sqrt(delta)) / (2 * a)
    print("X1: ", x1, 'X2: ', x2)
elif delta == 0:
    x1 = -b/(2 * a)
    print("X: ", x1)
else:
    delta = complex(b**2 - 4*a*c, 0)
    x1 = (-b - cmath.sqrt(delta)) / (2 * a)
    x2 = (-b + cmath.sqrt(delta)) / (2 * a)
    print("X1: ", x1, 'X2: ', x2)

