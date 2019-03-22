#!/usr/bin/env python

x = int(input())

if x % 7 == 0:
    print('Podzielna przez 7')
elif x % 3 == 0:
    print('Podzielna przez 3')
if 1 <= x <= 5:  # x in [1,2,3,4,5]
    print('W zakresie 1 - 5')