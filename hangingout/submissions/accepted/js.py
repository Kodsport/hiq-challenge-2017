#!/usr/bin/env python3
import random

L, x = map(int, input().split())

denied = 0
inside = 0
for i in range(x):
    event, people = input().split()
    people = int(people)
    if event == "enter":
        if inside + people <= L:
            inside += people
        else:
            denied += 1
    else:
        inside -= people

print(denied)
