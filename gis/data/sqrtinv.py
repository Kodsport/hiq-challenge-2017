N = 10 ** 6
print(N)
res = []
for i in range(1000):
    res.extend(list(reversed(range(i * 1000 + 1, i * 1000 + 1001))))
print(*res)
