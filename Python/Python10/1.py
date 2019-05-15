try:
    a = float(input('podaj liczbę a: '))
    b = float(input('podaj liczbę b: '))
except ZeroDivisionError as e:
    print(e)
else:
    print('a / b = ', a / b)
finally:
    print('koniec')