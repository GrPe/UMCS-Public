class A(object):
    def funkcja(self):
        print("wywolanie A")
    
class B(A):
    def funkcja(self):
        print("Wywolanie B")
        super(B, self).funkcja()

kl = B()
kl.funkcja()