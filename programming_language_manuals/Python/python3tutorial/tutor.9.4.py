class Warehouse:
  purpose = 'storage'
  region = 'west'

w1 = Warehouse()
print(w1.purpose, w1.region)

w2 = Warehouse()
w2.region = 'east'
print(w2.purpose, w2.region)
# Will this print east too? Expect YES, but tutorial implies NO.
# "attribute lookup prioritizes the instance"
# ANS: NO. "region" is an attribute of the class and therefore should be shared
# among its instances, but, if you assign a value to an attribute of the same
# name via an instance class, that attribute becomes a new value independent of
# the class attribute value.
print(w1.region)
print(Warehouse.region) # expect 'west'
print(w2.region) # expect 'east'
print(w2.__class__) # expect Warehouse. Got <class '__main__.Warehouse'>
print(Warehouse.__class__) # Does this work? Yes, but got <class 'type'>