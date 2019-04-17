class nicosc1: #klasa
    pass

class nicosc2(object): #dziedziczenie
    pass

class klasa:
    "Obiekt klasa"
    def funkcja(self):
        print("metoda klasy funkcja")

obj1 = nicosc1()
print(dir(obj1))

obj2 = nicosc2()
print(dir(obj2))

obiekt = klasa()
obiekt.funkcja()