"""
백준 숫자카드

첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이가 주어진다.
둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다.숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며,
이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

"""
import sys

# 이분탐색.
def solution(target,_list):
    start = 0
    end = len(_list)-1

    while start <= end:

        mid = (start+end) // 2

        if _list[mid] == target:
            return 1

        elif _list[mid] > target:
            end = mid - 1

        elif _list[mid] < target:
            start = mid + 1

    return 0

n = int(sys.stdin.readline().strip())
san_list = list(sys.stdin.readline().strip().split())

m = int(sys.stdin.readline().strip())
m_list = list(sys.stdin.readline().strip().split())

san_list = sorted(san_list)
answer_list =[0]*m

for i in range(len(m_list)):

    if solution(m_list[i], san_list):
        answer_list[i] = 1

for i in answer_list:
    print(i, end=" ")