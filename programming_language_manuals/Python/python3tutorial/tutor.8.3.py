class B(Exception):
    pass

class C(B):
    pass

class D(C):
    pass

for cls in [B, C, D]: ## cls=class # "the following code will print B, C, D in that order:" ## same order as the list on this line.
    try:
        raise cls() ## raise - valid since B is a subclass of Exception.
    except D:
        print("D")
    except C:
        print("C")
    except B:
        print("B")

# Note that if the except clauses were reversed (with except B first), it would
# have printed B, B, B — the first matching except clause is triggered.
# der: because C and D are subclasses of B.
for cls in [B, C, D]: # cls=class
    try:
        raise cls() # raise - valid since B is a subclass of Exception.
    except B:
        print("B")
    except D:
        print("D")
    except C:
        print("C")
