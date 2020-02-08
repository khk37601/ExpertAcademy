n = int(input())

for i in range(n):
    s = int(input())
    _list = [1, 1, 1]

    for j in range(2,s):
        _list.append(_list[j-2]+_list[j-1])

    print(_list[s-1])