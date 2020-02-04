"""
백준 ATM

P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2 인 경우를 생각해보자. [1, 2, 3, 4, 5]

3+4+8+11+13 = 39
"""
import sys
# 입력.
n = int(sys.stdin.readline().strip())
person_list = list(map(int, sys.stdin.readline().strip().split()))

# 최소 시간으로 이용 하기 위해서는 작은 수 부터 처리 해야 한다.
person_list = sorted(person_list)
time = 0
min_time = 0

for i in range(len(person_list)):

    time += person_list[i]
    min_time += time




print(min_time)