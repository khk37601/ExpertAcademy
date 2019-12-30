import sys
"""


마이너스 가호를 만날 때 다음 마이너스 까지 모든 수를 더하고 뺴면 된다,
"""
n = sys.stdin.readline().strip().split('-')


_list = []

for i in n:
    number = i.split('+')
    number = list(map(int, number))
    _list.append(sum(number))




# 다 더했으니 뺴기
_sum = _list[0]

for i in _list[1:]:
    _sum -= i

print(_sum)
















