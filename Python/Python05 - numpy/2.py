import numpy

t = numpy.arange(15).reshape(3, 5)
s = t.shape
t.shape = (5, 3)
print(t)
