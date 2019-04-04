import numpy
import matplotlib.pyplot as plt
import random

x = numpy.arange(0, 100, 2)
y = []
for i in range(0, 50):
    y.append(random.randint(0, 100))

plt.scatter(x, y)

# labels
plt.xlabel('Oś x')
plt.ylabel('Oś y')

plt.legend()

plt.show()
