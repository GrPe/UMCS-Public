import math

def foo(a, b):
    res = 0
    for i in range(0, len(a)):
        res += (b[i]-a[i])**2
    res = res**0.5
    return res

a = (-1.0, 0, 0)
b = (1.0, 0, 0)
print(foo(a, b))