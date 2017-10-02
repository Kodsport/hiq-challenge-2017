import re
import sys

INT = "(0|[1-9][0-9]*)"
INT3 = "{} {} {}\\n".format(INT, INT, INT)
INTS = "({} )*{}\\n".format(INT, INT)

line = sys.stdin.readline()
assert re.match(INT3, line)
N, s, t = map(int, line.split())
assert 1 <= N <= 10**5
assert 0 <= s < N
assert 0 <= t < N
assert s != t

sumcount = 0

for i in range(N):
    line = sys.stdin.readline()
    assert re.match("[NC] " + INTS, line)
    parts = list(map(int, line.split()[1:]))
    count = parts[0]
    ed = parts[1:]
    assert(len(ed) == count)
    assert(len(set(ed)) == count)
    sumcount += count
    for x in ed:
        assert 0 <= x and x < N
        assert x != i

assert sumcount <= 4*10**5

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
