#!/usr/bin/env python

l = [1, 5, 9, 4, 2, 7, 2, 4, 4, 0]

# 1
print(len(l))

# 2
print(l[-1])

# 3
print(l[3:])

# 4
print(l[0:len(l):2]) #lub print(l[::2])

# 5
print(l[::-2])

# 6
l.sort()

# 7
l.reverse()

# 8

l2 = []
for i in l:
    l2.append(str(i))

print(l2, sep=', ')
print(', '.join(l2))

# 9
lista = [0]*100
print(lista)

# 10

#l.append(int(input()))
#l.append(int(input()))
#l.append(int(input()))
print(l)

l[::2] = [0]*5
print(l)