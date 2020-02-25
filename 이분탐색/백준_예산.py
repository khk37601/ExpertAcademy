"""
백준 예산

모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다.
상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다.

120, 110, 140, 150

 <= m  최대값은 m을 넘어서서 수 없다.

"""
import sys


def solution(money, budget_list, m):
    start = 0
    end = money
    result = 0

    while start <= end:

        budget = (start+end )//2
        total = 0
        for i in budget_list:
            if i > budget:
                total += budget
            else:
                total += i

        if total <= m:
            result = budget
            start = budget + 1
        else:
            end = budget - 1

    return result


n = int(sys.stdin.readline().strip())
budget_list = list(map(int, sys.stdin.readline().strip().split()))
m = int(sys.stdin.readline().strip())
print(solution(max(budget_list), budget_list, m))