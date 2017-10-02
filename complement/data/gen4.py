#!/usr/bin/env python3
# n nodes, all in a cycle, each complement of the next node.
# Should have ans = n-1.

from generator import *

n = int(cmdlinearg('n'))

gr = []
for i in range(n):
    a = list(range(n))
    j = (i+1) % n
    del a[j]
    del a[a.index(i)]
    gr.append(('C', a))

print_graph(gr, 0, n-1)
