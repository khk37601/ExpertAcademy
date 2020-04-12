import sys

n = sys.stdin.readline().strip()

_list = [False for _ in range(9)]

for number in n:

    index = int(number)
    # 6,9를 같이 취급
    if index == 9:
        index = 6

    _list[index] += 1

# 결국은 2로 나누면 된다.
## 9999 4개 이지만 결국은 2세트가 필요한 것이니까
_list[6] = (_list[6]+1) // 2

print(max(_list))

