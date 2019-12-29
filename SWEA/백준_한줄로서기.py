import sys

n = int(input())
data = [-1] + list(map(int,sys.stdin.readline().split()))
result = [-1]*n
index = list(range(n))

for i in range(1, n+1):
    result[index.pop(data[i])] = i

print(' '.join(str(e) for e in result))

