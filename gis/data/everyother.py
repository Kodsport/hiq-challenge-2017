N = 10 ** 6
print(N)
ans = list(range(1, N + 1))
for i in range(N // 2):
    ans[2 * i], ans[2 * i + 1] = ans[2 * i + 1], ans[2 * i]
print(*ans)
