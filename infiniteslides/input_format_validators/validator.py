import re
import sys

INT = "(0|[1-9][0-9]*)(\\.[0-9]{1,6})?\\n"

line = sys.stdin.readline()
assert re.match(INT, line)
K = float(line)
assert 0 <= K <= 1000

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
