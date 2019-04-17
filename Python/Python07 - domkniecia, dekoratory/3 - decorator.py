#dekorowanie

def g(x):
    print(x)

def decorator(f):
    def _f(*args, **kwargs):
        print('-->')
        f(*args, **kwargs)
        print('<--')
    return _f

decorator(g)("text")


def decorator2(a, b):
    def _decorator(f):
        def _f(*args, **kwargs):
            print(a)
            f(*args, **kwargs)
            print(b)
        return _f
    return _decorator

