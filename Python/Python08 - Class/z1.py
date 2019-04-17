import math

class LiczbaZespolona:
    def __init__(self, a, b):
        self.a = a
        self.b = b
    
    def __add__(self, other):
        return LiczbaZespolona(self.a + other.a, self.b + other.b)

    def __sub__(self, other):
        return LiczbaZespolona(self.a - other.a, self.b - other.b)
    
    def __mul__(self, other):
        return LiczbaZespolona(self.a * other.a - self.b * other.b,
                                self.a * other.b + self.b * other.a)

    def __truediv__(self, other):
        if other.a == 0 and other.b == 0:
            return LiczbaZespolona(0,0)
        __temp = self * LiczbaZespolona(other.a, -other.b)
        __temp.a /= (other.a**2 + other.b**2)
        __temp.b /= (other.a**2 + other.b**2)
        return __temp

    def modul(self):
        return math.sqrt(self.a**2 + self.b**2)

    def __str__(self):
        return str(self.a) + " " + str(self.b)+"i"

    def __eq__(self, other):
        if self.a == other.a and self.b == other.b:
            return True
        return False
    
z = LiczbaZespolona(1, 2)
z1 = LiczbaZespolona(3, -4)

z3 = z / z1
print(z3)