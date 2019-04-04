import random
import numpy
import matplotlib.pyplot as plt

rule = 126 #regula
k = 100   #ilosc ileracji
n = 64    #wielkosc 
predict = ["***","**.","*.*","*..",".**",".*.","..*","..."]
prerule = ["."*int(i=='0')+"*"*int(i=='1') for i in str(bin(rule))[2:].zfill(8)]
automat = {key: value for (key, value) in zip(predict, prerule)}
### losowy automat n elementowy
# cells = "".join(random.choice(".*") for i in range(n))
### automat nielosowy
cells = "."*31 + "*" + "."*31
n = len(cells)
for i in range(0,k):
    # print(cells)

    x = []
    y = []
    for z in range(0, len(cells)):
        if cells[z] == '*':
            x.append(z)
            y.append(k - i)
    plt.scatter(x, y, marker='^', color ='black', s=8)

    cells = "".join(automat[cells[i-1]+cells[i]+cells[(i+1)*int(i<n-1)]] for i in range(0,n))

plt.show()