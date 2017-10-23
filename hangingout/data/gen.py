import random

L = random.randint(100, 200)
x = 100

print(L, x)
inside = 0
for i in range(x):
    if not inside or random.randint(0, 2) <= 1:
        enter = random.randint(1, 200)
        print("enter {}".format(enter))
        if inside + enter <= L:
            inside += enter
    else:
        leave = random.randint(1, inside)
        print("leave {}".format(leave))
        inside -= leave
