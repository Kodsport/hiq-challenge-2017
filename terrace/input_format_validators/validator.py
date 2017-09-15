import sys
import re
import random

INT = "(0|[1-9][0-9]*)?"
TWO_INT = INT + " " + INT + "\\n"
EVENT = "(enter|leave) " + INT + "\\n"

line = sys.stdin.readline()
assert re.match(TWO_INT, line)
L, x = map(int, line.split())
assert 0 <= x <= 100 and 1 <= L <= 200

inside = 0
for i in range(x):
    line = sys.stdin.readline()
    assert re.match(EVENT, line)
    event, people = line.split()
    people = int(people)
    assert 1 <= people <= 200

    if event == "enter":
        if inside + people <= L:
            inside += people
    else:
        assert people <= inside
        inside -= people

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
