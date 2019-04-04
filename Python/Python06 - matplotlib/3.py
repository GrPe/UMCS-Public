import numpy
import matplotlib.pyplot as plt

x = numpy.arange(0, 2, 0.1)

plt.plot(x, x, 'r--', label="x=y")
plt.plot(x, x**2, 'bs',  label='x^2')
plt.plot(x, x**3, 'g^', label='x^3')

# labels
plt.xlabel('Oś x')
plt.ylabel('Oś y')

plt.legend()

plt.show()
