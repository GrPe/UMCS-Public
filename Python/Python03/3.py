import os

for x in os.listdir('.'):
    if x.split('.')[-1] != 'py':
        print(x)