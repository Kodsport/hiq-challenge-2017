import sys
import math
import random

x = int(sys.argv[1])
add = x * math.pi / 12

v = random.randint(0, 300) * math.pi + add
print("{:.6f}".format(v))
