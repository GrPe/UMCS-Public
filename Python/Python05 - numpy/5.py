import numpy
import math

def transform(vec, angle):
    angle = math.radians(angle)
    matrix = numpy.array([[math.cos(angle), math.sin(angle)],
                          [-math.sin(angle), math.cos(angle)]])
    return numpy.matmul(vec, matrix)


vec = numpy.array([1, 0])
angle = 90

print(transform(vec, angle))