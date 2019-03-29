import numpy

data = numpy.genfromtxt('data.csv', dtype=numpy.float32, delimiter=',')

# 2
print(data[:, 1])

# 3
print(data[::2, :])

# 4
print(data.flat[:])

# 5
print("\n\n\n")
data.shape = (7, 5, 2)
print(data)

# 6
print("\n\n\n6")
print(numpy.sum(data, axis = None))
