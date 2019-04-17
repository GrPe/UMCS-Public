is_logged = False

def foo():
    print("aaa")

def login_required(f):
    def _f():
        if is_logged:
            print("user is logged")
            f()
        else:
            print("user is not logged")
    return _f

login_required(foo)()