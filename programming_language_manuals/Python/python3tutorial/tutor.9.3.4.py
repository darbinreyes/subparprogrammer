class MyClass:
    """A simple example class"""
    i = 12345

    def f(self):
        return 'hello world'

# Error ? ANS: Yes. You need to pass in self.
# MyClass.f()

x = MyClass()

print(MyClass.f(x)) # Works