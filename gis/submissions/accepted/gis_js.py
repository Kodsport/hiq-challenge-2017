#!/usr/bin/env python3
N = int(input())
xs = list(map(int, input().split()))
res = []
for x in xs:
    if not res or x > res[-1]:
        res.append(x)
print(len(res))
print(*res)
