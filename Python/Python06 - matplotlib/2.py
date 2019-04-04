import numpy
import matplotlib.pyplot as plt

plt.plot( [1, 2, 3, 4], [1, 3, 4, 7])

# labels
plt.xlabel('Oś x')
plt.ylabel('Oś y')

plt.axis([0, 3, -3, 4])

plt.show()
