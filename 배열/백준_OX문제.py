import sys


n = int(sys.stdin.readline().strip())

for _ in range(n):
    line = list(sys.stdin.readline().strip())
    plus = 0
    total = 0
    for ox in line:
        if ox == "O":
            plus += 1
            total += plus
        else:
            plus = 0

    print(total)