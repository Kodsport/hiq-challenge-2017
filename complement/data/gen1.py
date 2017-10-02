#!/usr/bin/env python3
# A uniformly random graph with n normal vertices, c complement vertices, and ~m edges,
# of which k are adjacent to start/end.

from generator import *
import random

n1 = int(cmdlinearg('n'))
n2 = int(cmdlinearg('c'))
m = int(cmdlinearg('m'))
k = int(cmdlinearg('k'))

assert 2*k <= m

n = n1 + n2
s = 0
t = 1

tp = list('N' * n1 + 'C' * n2)
random.shuffle(tp)
gr = [(tp[i], []) for i in range(n)]
seen = set()
for it in range(m):
    a = random.randrange(n)
    b = random.randrange(n)
    if it >= m - 2*k:
        if it >= m - k:
            a = s
        else:
            b = t
    if a == s and b == t and gr[a][0] == 'N':
        # too easy...
        continue
    if a != b and (a, b) not in seen:
        gr[a][1].append(b)
        seen.add((a, b))

print_graph(gr, s, t)
