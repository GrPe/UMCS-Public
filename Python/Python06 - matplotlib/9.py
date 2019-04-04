import numpy
import matplotlib.pyplot as plt

def f(t):
	return numpy.exp(-t) * numpy.cos(2*numpy.pi*t)

t1 = numpy.arange(0, 5, 0.1)
t2 = numpy.arange(0, 5, 0.02)

plt.figure(1)
plt.subplot(211)

plt.plot(t2, f(t2))
plt.scatter(t1, f(t1))

plt.subplot(212)

plt.plot(t2, numpy.cos(t2*5), linestyle='--', color='r')


# labels
plt.xlabel('Oś x')
plt.ylabel('Oś y')

plt.legend()


plt.show()
