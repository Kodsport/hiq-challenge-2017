import re
import sys

INT = "(0|[1-9][0-9]*)\\n"
INTS = "((0|[1-9][0-9]*) )*(0|[1-9][0-9]*)\\n"

line = sys.stdin.readline()
assert re.match(INT, line)
K = int(line)
assert 1 <= K <= 10**6

line = sys.stdin.readline()
assert re.match(INTS, line)
xs = list(map(int, line.split()))
assert len(xs) == K
for x in xs: assert 0 <= x <= 2**30

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
