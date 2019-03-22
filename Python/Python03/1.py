def generator(n):
    while n:
        print('zwraca %d z generatora' %n )
        yield n
        n-=1


for x in generator(10):
    print(x)
