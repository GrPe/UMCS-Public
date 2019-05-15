class CharError(Exception):
    def __str__(self):
        return 'CharError'

class DateError(Exception):
    def __str__(self):
        return 'DateError'
    
class SumError(Exception):
    def __str__(self):
        return 'SumError'

a = 0

try:
    #input data
    try:
        a = int(input('Podaj PESEL: '))
    except:
        raise CharError
    
    if len(str(a)) != 11:
        raise CharError

    if int(str(a)[2:4]) > 32:
        raise DateError
    if int(str(a)[4:6]) > 31:
        raise DateError

    #check sum
    check = [9,7,3,1,9,7,3,1,9,7]
    sum = 0
    iter = 0

    pesel = str(a)

    for x in check:
        sum = sum + int(pesel[iter])*x
        iter = iter + 1

    sum %=10

    if sum != int(str(a)[-1]):
        raise SumError

except Exception as e:
    print(e)

else:
    print("OK")