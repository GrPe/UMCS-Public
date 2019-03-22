def fun(napis):
    ret=[(x, len(x)) for x in napis.split()]
    return ret

print(fun("ALA MA KOTA"))
