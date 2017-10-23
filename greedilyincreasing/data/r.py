import random

N = 10 ** 6
print(N)
x = list(range(1, N + 1))
random.shuffle(x)
print(*x)
