import re
import sys

INT = "(0|[1-9][0-9]*)\\n"
INTS = "((0|[1-9][0-9]*) )*(0|[1-9][0-9]*)\\n"

line = sys.stdin.readline()
assert re.match(INT, line)
N = int(line)
assert 1 <= N <= 10**6

line = sys.stdin.readline()
assert re.match(INTS, line)
xs = list(map(int, line.split()))
assert list(sorted(xs)) == list(range(1, N + 1))

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
