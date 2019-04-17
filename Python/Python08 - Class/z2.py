import math

class Punkt2D:
    x= 0
    y = 0

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __sub__(self, other):
        return math.sqrt((other.x - self.x)**2 + (other.y - self.y)**2)

    def __str__(self):
        return str(self.x) + ", " + str(self.y)


class Punkt3D(Punkt2D):
    z = 0

    def __init__(self, x, y, z):
        Punkt2D.__init__(self, x, y)
        self.z = 0

    def __sub__(self, other):
        return math.sqrt((other.x - self.x)**2 + (other.y - self.y)**2 + (other.z - self.z)**2)

    def __str__(self):
        return "(" + str(self.x) + ", " + str(self.y) + ", " + str(self.z) + ")"

p1 = Punkt3D(1, 2, 0)
p2 = Punkt3D(2, 2, 0)

p3 = p1 - p2
print(p1)
print(p3)