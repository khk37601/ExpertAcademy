import sys

_list = []
n = int(input())


for i in range(n):
    _list.append(list(map(int, sys.stdin.readline().split())))


rank_list = []


for loop in range(len(_list)):

    w, h = _list.pop(0)
    cnt = 1

    for i, j in _list:

        if i > w  and  j > h :
            cnt +=1

    rank_list.append(str(cnt))
    _list.append((w,h))

print(' '.join(rank_list))


