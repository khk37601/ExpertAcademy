import sys


n, m = map(int, sys.stdin.readline().strip().split())
_list = list(map(int, sys.stdin.readline().strip().split()))
length = len(_list)
max_list = []
for i in range(length):
    for j in range(i+1, length):
        for z in range(j+1,length):
            print(_list[i],_list[j],_list[z])
            max_list.append(sum([_list[i],_list[j],_list[z]]))



tmp = [i for i in max_list if i<=m]

print(max(tmp))
