import numpy
import matplotlib.pyplot as plt

x = ["Python", "C++", "Java", "Rubby"]
y = [100, 30, 50, 10]

plt.bar(x, y)

# labels
plt.xlabel('Oś x')
plt.ylabel('Oś y')

plt.legend()

plt.show()
