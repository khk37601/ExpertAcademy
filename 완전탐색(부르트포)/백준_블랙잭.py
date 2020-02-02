"""
백준 블랙잭
 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다.
 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는다.

합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.
"""
import sys

# 입력.
n, m = map(int, sys.stdin.readline().split())
_list = list(map(int, sys.stdin.readline().strip().split()))

"""
  N의 범위가 100이다. 완적탐색으로 풀 수 있다.
  
"""

answer = 0
answer_list = []

for loop in _list:
    for loop2 in _list:
        # 중복 허용 x
        if loop2 != loop:
            for loop3 in _list:
                # 중복 허용 x
                if loop3 != loop2 and loop3 != loop:
                    # 합 저장.
                    answer_list.append(sum([loop, loop2, loop3]))

# 최대값보다 같거나 작은 값 중에서 가장 큰값을 설정,
answer = [i for i in answer_list if i <= m]

print(max(answer))


