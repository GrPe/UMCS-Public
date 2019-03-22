#!/usr/bin/env python
# fibonacci


def fib(n):
    first, second = 0, 1
    while n > 1:
        # print(first, end=' ')
        first, second = second, first + second
        n -= 1
    return first


n = int(input())
print(fib(n))




