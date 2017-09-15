L = [2**30] + [0] * 29 + [1]
L2 = [2**30 - 1] + [0] * 29 + [1]
K = 10**6
K = K - K % 31

its = K // len(L2) - 1
R = L + L2 * its
print(len(R))
print(*R)
