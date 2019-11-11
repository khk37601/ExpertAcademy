import sys


miner = [1, 2, 3, 4, 5]


for test_case in range(1, 11):

    n = input()
    _list = list(map(int, sys.stdin.readline().strip().split()))

    index = 0

    while True:
        number = _list[0]
        # 삭제
        del _list[0]

        if index >= 5:
            index = 0

        _sum = number - miner[index]
        index += 1

        if _sum <= 0:
            _list.append(0)
            break
        else:
            _list.append(_sum)

    print('#{}'.format(n), ' '.join(map(str, _list)))