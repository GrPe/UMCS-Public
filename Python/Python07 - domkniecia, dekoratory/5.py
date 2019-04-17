import math

def foo(a, b):
    if len(a) < len(b):
        a = a + (0,)*(len(b)-len(a))
    else:
        b = b + (0,)*(len(a) - len(b))
    res = 0
    for i in range(0, len(a)):
        res += (b[i]-a[i])**2
    res = res**0.5
    return res

b = (-1, -1)
a = (1.0, 0, 0, 0,0)
print(foo(a, b))