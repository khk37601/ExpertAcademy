"""
백준 회의실배정

회의시간이 일찍끝나는 기준으로 설정.

2
10 10
1 10
->도출 2

1 10 , 10 10 2개

10 10 , 1 10  1개

    (1)
    끝나는 시간이 가장 빠른 순으로 정렬
    (2)
    시작하는 시간의 오름차순

"""
import sys


def solution(meeting):
    count = 0
    end_time = 0

    for i in meeting:
        if i[0] >= end_time:
            end_time = i[1]
            count +=1

    return count


# 입력.
n = int(sys.stdin.readline().strip())
meeting = []

for i in range(n):
    start, end = map(int, sys.stdin.readline().strip().split())
    meeting.append((start, end))

    """
    (1)
    끝나는 시간이 가장 빠른 순으로 정렬
    (2)
    시작하는 시간의 오름차순
    """
meeting.sort(key = lambda x:(x[1],x[0]))


print(solution(meeting))