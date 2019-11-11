

n = int(input())

for test_case in range(n):

    n = int(input())
    string = input()

    _list = []
    length = len(string)

    for i in range(length):
        for j in range(length+1):

            _list.append(string[i:j+i+1])

            if j+i+1 >= length:
                break

    # 중복제거 후 정렬.
    _list = sorted(set(_list))

    if len(_list) <= n:
        print('#{} {}'.format(test_case+1, 'none'))
    else:
        print('#{} {}'.format(test_case+1, _list[n-1]))
