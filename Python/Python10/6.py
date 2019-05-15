
f = open('bacillus_dna.txt', 'r')

s = f.readlines()

out = open('out','wb')

a = 0
b = b''

for x in s:
    if(a % 4 == 0):
        out.write(b.decode('ascii'))
        b = b''
    if x == 'A':
        b = b + b'\x00'
    elif x == 'C':
        b = b + b'\x01'
    elif x == 'T':
        b = b + b'\x03'
    elif x == 'G':
        b = b + b'\x02'



out.close()