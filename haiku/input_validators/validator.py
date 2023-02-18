import re
import sys

INT = "(0|[1-9][0-9]*)?\\n"
SYLLABLE = "[a-z]{1,7}\\n"
POEM = "([a-z]{1,100} )*[a-z]{1,100}\\n"

line = sys.stdin.readline()
assert re.match(INT, line)
S = int(line)
assert 1 <= S <= 100

syl = set()
for i in range(S):
    line = sys.stdin.readline()
    assert re.match(SYLLABLE, line)
    s = line.strip()
    assert s not in syl
    syl.add(s)

poem = [sys.stdin.readline() for _ in range(3)] 
for x in poem: assert re.match(POEM, x) and len(x.strip()) <= 100
poem = list(map(lambda x: x.strip(), poem))

for x in poem:
    ok = [True if i == len(x) else False for i in range(len(x) + 1)]
    for i in range(len(x) - 1, -1, -1):
        if x[i] == ' ': ok[i] = ok[i + 1]
        for k in range(1, 8):
            if i + k <= len(x):
                s = x[i:i+k]
                if s in syl:
                    ok[i] = ok[i] or ok[i + k]
    assert ok[0]

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
