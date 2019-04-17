class A:
    def __init__(self, zmienna):
        self.zmienna = zmienna
    def __add__(self, other):
        return self.zmienna + other.zmienna

a = A(5)
b = A(8)

print(a+ b)