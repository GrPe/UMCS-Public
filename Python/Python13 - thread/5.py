import threading

i = 0

def increase(i):
    for x in range(1000000):
        i += 1
    return

def decrease(i):
    for x in range(1000000):
        i -= 1
    return

thread1 = threading.Thread(target=increase, args=(i,))
thread2 = threading.Thread(target=decrease, args=(i,))


thread1.start()
thread2.start()

print(i)