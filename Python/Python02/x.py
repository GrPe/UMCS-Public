#!/usr/bin/env python

l = [2, 7, -4, 5, 3, -6, 2, 1]

for x in range(0, len(l)):
    if sum(l[:x]) == sum(l[x:]):
        print(x)
        break
