import numpy
import matplotlib.pyplot as plt

x = numpy.linspace(-10, 10, 100)

plt.plot(x, x**2, label='1. -', linestyle='-', linewidth=2.0)
plt.plot(x, 0.5*x**2, label='2. --', linestyle='--', linewidth=2.0)
plt.plot(x, 0.4*x**2, label='3. -.', linestyle='-.')
plt.plot(x, 0.3*x**2, label='4. :', linestyle=':')
plt.plot(x, 0.2*x**2, label='5. None', linestyle=None)

# labels
plt.xlabel('Oś x')
plt.ylabel('Oś y')

plt.legend()


plt.show()
