class Klasa:
    atr1 = 0
    __atr2 = 2 #zmienna prywatna

    def setAtr2(self, zmienna):
        self.__atr2 = zmienna

    def setAtr3(self, zmienna):
        self.atr3 = zmienna #publiczny atrybut

    def add(self):
        return self.atr1 + self.__atr2 + self.atr3


klasa = Klasa()
klasa.setAtr2(13)
klasa.setAtr3(1)
print(klasa.add())

