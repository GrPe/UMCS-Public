import numpy

vec = numpy.array([1, 2])
matrix = numpy.array([[1, 0],
                      [0, 1]])

x = numpy.matmul(vec, matrix)

print(x)