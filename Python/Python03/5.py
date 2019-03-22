f = open('text.txt', 'r')

data = []
counter = 0
c = 0
i = -1
line = f.readline()
while line:
    i = line.find('AATT', i + 1)
    if i != -1:
        data.append((c//70, c + i))
        # print("%d: %d"%(c/70, c + i))
    else:
        c += 70
        i = -1
        line = f.readline()
for x in data:
    print(x)
print(len(data))