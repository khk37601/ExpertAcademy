"""
백준 괄호

 스택문제 중 에서 가장 대표적인 문제.

"""
import sys

def solution(string):
    stack = []
    # 열린 괄호는 넣는다.
    for i in string:
        if i == '(':
            stack.append(i)
        else:
            if stack:
                stack.pop()
            else:
               return "NO"

    if stack:
        return "NO"

    return "YES"


# 입력
T = int(input())

for i in range(T):
    string = sys.stdin.readline().strip()
    print(solution(string))
