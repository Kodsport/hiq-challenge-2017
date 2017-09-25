#!/usr/bin/env python3
MOD = 1000000007

K = int(input())
leave = 0
cur = 1
extras = 0
xs = list(map(int, input().split()))
for has in xs:
    has += extras
    if (has&1) and not extras: leave = (leave + cur) % MOD
    extras = has // 2
    cur = (cur * 2) % MOD
print(leave)
