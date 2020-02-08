import sys

n = int(input())


_list= [1, 2]


for i in range(2,n+1):

    _list.append((_list[i-2]+_list[i-1])%15746)

print(_list[n-1])