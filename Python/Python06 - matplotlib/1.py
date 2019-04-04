import numpy
import matplotlib.pyplot as plt

x = numpy.linspace(0, 2, 100)

plt.plot(x, x**2, label='quadratic')

# labels
plt.xlabel('Oś x')
plt.ylabel('Oś y')

plt.title('Prosty wykres')
plt.legend()

plt.show()

# plt.savefig('fig.png')
