import numpy

def scalar(a, b):
    if a.size != b.size:
        return None
    result = 0
    for x, y in zip(a, b):
        result += x*y
    return result

a = numpy.arange(5)
b = numpy.arange(5)

print(scalar(a, b))