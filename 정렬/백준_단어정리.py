import sys

lists = []
for _ in range(int(sys.stdin.readline().strip())):
    word = sys.stdin.readline().strip()
    lists.append((word, len(word)))

lists = list(set(lists))
lists.sort(key=lambda x: (x[1], x[0]))
print("\n".join(_[0] for _ in lists))