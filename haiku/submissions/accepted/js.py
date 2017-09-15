#!/usr/bin/env python3
import sys

line = sys.stdin.readline()
S = int(line)

syllables = set()
for i in range(S):
    line = sys.stdin.readline()
    syllable = line.strip()
    syllables.add(syllable)

poem = [sys.stdin.readline() for _ in range(3)] 
poem = list(map(lambda x: x.strip(), poem))

decomp = []
for line in poem:
    decomps = [set([0]) if i == len(line) else set() for i in range(len(line) + 1)]
    for pos in range(len(line) - 1, -1, -1):
        if line[pos] == ' ': decomps[pos] = decomps[pos + 1]
        for syllable_length in range(1, 8):
            new_pos = pos + syllable_length
            if new_pos <= len(line):
                syllable = line[pos:new_pos]
                if syllable in syllables:
                    decomps[pos] = decomps[pos] | set([s + 1 for s in decomps[new_pos]])
    decomp.append(decomps[0])

if 5 in decomp[0] and 7 in decomp[1] and 5 in decomp[2]:
    print("haiku")
else:
    print("come back next year")
