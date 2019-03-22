#!/usr/bin/env python


def silnia(n):
    if n == 0:
        return 1
    return silnia(n-1)*n


def pow(a, b):
    return a+b


# n = int(input())
# print(silnia(n))
# print(pow(b=10, a=2))
print(pow([1, 2], ['ala']))

print(len('ala ma kota'))