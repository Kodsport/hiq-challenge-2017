import random
K = 10**6
print(K)
print(*[0 if random.randint(0, 10) != 10 else random.randint(1,1000) for i in range(K)])
