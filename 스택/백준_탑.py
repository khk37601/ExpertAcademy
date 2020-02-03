"""
백준 탑

첫째 줄에 탑의 수를 나타내는 정수 N이 주어진다. N은 1 이상 500,000 이하이다.
둘째 줄에는 N개의 탑들의 높이가 직선상에 놓인 순서대로 하나의 빈칸을 사이에 두고 주어진다.
탑들의 높이는 1 이상 100,000,000 이하의 정수이다.

탑의 송출 방향은 왼쪽.
"""
import sys

n = int(sys.stdin.readline())
top_stack = list(map(int, sys.stdin.readline().strip().split()))
answer = [0]*n


for i in range(len(top_stack), -1, -1):
    



for i in range(len(top_stack), -1, -1):
    if top_stack:
        top_len = top_stack.pop()
        index = len(top_stack)
        if index == 0:
            break

        for j in top_stack[::-1]:
            if j > top_len:
                answer[i-1] = index
                break
            index -=1




print(answer)