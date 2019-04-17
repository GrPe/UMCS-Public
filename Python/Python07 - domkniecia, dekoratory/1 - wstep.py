a = 2
b = 5

def f(a, b = 1):
    '''
    To jest funkcja, ktora nic nie robi.
    '''
    pass

def suma(x, y):
    return x + y

#wiele parametrow

def foo(*a, **b): # a bedzie krotka z wieloma wartosciami
    print(a[1:])      # **b parametry zostana przekazane przez slownik
    print(b['b'])

x = (1, 2, 3)
y = {'a': 3, 'b': 7}
foo(*x, **y)

# print(suma(1, 2))


xx = (2, 5, 3, 8, 5, 6)

def Max(*a):
    return max(a)

print(Max(*xx))

