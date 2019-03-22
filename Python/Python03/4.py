import os

os.remove("test2.txt")

if os.path.exists('test.txt'):
    os.remove('test.txt')
else:
    print('asdas')