#!/usr/bin/env python3
# k path nodes; path node i leads to a complement node, which forbids i+2 onwards.
# Padded with extra nodes until n to make things slower, in the form of a long path
# between path node k-2 and 0.
# Should have ans ~ 2k. Set k ~ sqrt(nlim).

from generator import *

k = int(cmdlinearg('k'))
n = int(cmdlinearg('n'))

assert 2*k < n

s = 0
t = 2*k-1
gr = []
for i in range(k):
    ar = [k + i]
    if i >= 4:
        # confound things more, don't hurt
        ar.append(i-1)
    if i == k-2:
        ar.append(2*k)
    gr.append(('N', ar))
for i in range(k):
    ar = list(range(min(i+2, k), k)) + list(range(min(k+i+1, 2*k), 2*k))
    gr.append(('C', ar))

for i in range(2*k, n):
    gr.append(('N', [(i+1) % n]))

print_graph(gr, s, t)
