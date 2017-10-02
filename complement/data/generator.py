#!/usr/bin/env python3
import random
import sys

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False, "Missing argument: " + name

def print_graph(graph, s, t):
    n = len(graph)
    ren = list(range(n))
    random.shuffle(ren)
    graph2 = [None] * n
    for i in range(n):
        graph2[ren[i]] = graph[i]
    print(n, ren[s], ren[t])
    for (tp, adj) in graph2:
        adj2 = [ren[x] for x in adj]
        random.shuffle(adj2)
        print(tp, len(adj2), *adj2)

random.seed(int(sys.argv[-1]))
