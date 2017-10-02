#!/usr/bin/env python3
# Short path to a lot of complement nodes, all except k of which forbid a
# random set + a short path to the end node.
# Should have ans = 5, except for k = 0 which has no solution.

from generator import *

n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))

s = 0
t = 2
gr = []
gr.append(('N', [3])) # 0->3
gr.append(('N', [2])) # 1->2
gr.append(('N', [0])) # 2->0
gr.append(('N', [4])) # 3->4
gr.append(('N', range(5, n-5))) # 4 -> most above
for i in range(5, n):
    st = list(random.sample(range(0, n), random.randint(0, 3)))
    if 1 not in st and i-5 >= k:
        st.append(1)
    if 2 not in st:
        st.append(2)
    if i in st:
        del st[st.index(i)]
    gr.append(('C', st))

print_graph(gr, s, t)
