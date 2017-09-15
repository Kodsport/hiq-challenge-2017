import sys
import string
import random

def syllable():
    l = random.randint(1, 7)
    return ''.join([random.choice(string.ascii_lowercase) for _ in range(l)])

def line(v):
    poem = [random.choice(syls) for i in range(v)]
    words = random.randint(1, v)
    breaks = random.sample(range(v - 1), v - 1)
    return ''.join([word + (" " if i in breaks else "") for i, word in enumerate(poem)])

syls = list(set([syllable() for _ in range(100)]))
print(len(syls))
for x in syls:
    print(x)

mode = sys.argv[1]
if mode == "haiku":
    print(line(5))
    print(line(7))
    print(line(5))
else:
    print(line(5 + random.randint(-1, 1)))
    print(line(7 + random.randint(-1, 1)))
    print(line(5 + random.randint(-1, 1)))
