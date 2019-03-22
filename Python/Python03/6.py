import random

s = input()

dict = {0: "A", 1: "C", 3: "T", 2: "G"}
redict = {"A": 0, "C": 1, "T": 3, "G": 2}

result = ''
for x in s:
    str = ''
    b = int(bin(ord(x)), 2)
    for y in range(0, 4):
        c = b & 3
        b = b >> 2
        str = dict[c] + str
    result += str
print(result)

key = ''
crypto = ''
for x in result:
    key += dict[random.choice(["A", "C", "T", "G"])]
    crypto += dict[redict[key] ^ redict[x]]

print(key)
print(crypto)
