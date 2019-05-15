l = range(10)
fl = filter(lambda x: x%2 == 0, l)

#for x in fl:
#    print(x)

def is_negative(item):
    return item < 0

l2 = range(-5,5)
fl2 = filter(is_negative, l2)

for x in fl2:
    print(x)