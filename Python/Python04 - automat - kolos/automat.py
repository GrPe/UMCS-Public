
import sys
import random


def generate(n):
    ciag = []
    for x in range(0, n):
        ciag.append(random.choice(['_', '*']))
    return "".join(ciag)


def swap(x):
    if x == '1':
        return '*'
    else:
        return '_'


def toDecimal(x):
    ret = []
    for i in x:
        if i == '*':
            ret.append('1')
        else:
            ret.append('0')
    return "".join(ret)


def createDictionary(rule):
    return {
        "***": swap(rule[0]), "**_": swap(rule[1]),
        "*_*": swap(rule[2]), "*__": swap(rule[3]),
        "_**": swap(rule[4]), "_*_": swap(rule[5]),
        "__*": swap(rule[6]), "___": swap(rule[7])
    }


# command line parameters
if len(sys.argv) == 2:
    fileToRead = open(sys.argv[1], "r")
    rule = str(bin(int(fileToRead.readline().split(' ')[1])))[2:].zfill(8)
    n = int(fileToRead.readline().split(' ')[2])
    k = int(fileToRead.readline().split(' ')[1])
    ciag = fileToRead.readline()
    fileToRead.close()
else:
    rule = str(bin(int(sys.argv[1])))[2:].zfill(8)
    n = int(sys.argv[2])
    k = int(sys.argv[3])
    ciag = generate(n)

transition = createDictionary(rule)


# file
file = open("automat.txt", "w")
file.write("rugula: " + str(rule) + '\n')
file.write("liczba krokow:" + str(k) + "\n")
file.write(ciag + '\n')

stats = [0]*256

for j in range(0, k):
    finalCiag = []
    for i in range(0, len(ciag)):
        if i == 0:
            temp = "".join(['_', ciag[i], ciag[i+1]])
            finalCiag.append(transition[temp])
        elif i == len(ciag)-1:
            temp = "".join([ciag[i - 1], ciag[i], '_'])
            finalCiag.append(transition[temp])
        else:
            temp = "".join([ciag[i-1], ciag[i], ciag[i+1]])
            finalCiag.append(transition[temp])
    ciag = "".join(finalCiag)
    file.write(ciag + "\n")
    stats[int(toDecimal(ciag), 2)] += 1

file.close()

f = open("output.txt", 'w')
for x in stats:
    f.write(str(x) + '\n')
f.close()
