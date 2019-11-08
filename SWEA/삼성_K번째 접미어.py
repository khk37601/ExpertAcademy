
test_case = int(input())


for i in range(test_case):
    k, string = int(input()), input()
    _list = [string[i:] for i in range(len(string))]
    _list.sort()

    if k >= len(_list):
        print("#{} none".format(i+1))
    else:
        print("#{} {}".format(i+1, _list[k-1]))

