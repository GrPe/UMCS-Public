
def foo(a):
    def f(b):
        print(a + ": " + str(b))
    return f

debug = foo("log")
debug(12)