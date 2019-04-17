# domkniecia

def dodaj(x):
    def a(y):
        return x + y
    return a

dodaj_5_do = dodaj(5)
dodaj_1_do = dodaj(1)
print(dodaj_5_do(2))
print(dodaj_1_do(2))

print(dodaj(5)(4))