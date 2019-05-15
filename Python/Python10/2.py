try:
    a = int(input('podaj liczbę: '))
    d = {'a': a}
    print(d['b'])
except ValueError:
    print("value error")
except KeyError:
    print("key error")
except:
    print('unknown')
    raise