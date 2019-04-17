class samochod:
    kolor = None
    def setColor(self, kolor):
        self.kolor = kolor

class osobowy(samochod):
    marka = "Mercedes"

sam = osobowy()
sam.setColor("niebieski")
print("To jest %s %s" %(sam.kolor, sam.marka))

