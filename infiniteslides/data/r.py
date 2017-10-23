import random

v = str(random.randint(0,999999))
v = "0" * (6 - len(v)) + v
x = str(random.randint(0,999)) + "." + v
print(x)
