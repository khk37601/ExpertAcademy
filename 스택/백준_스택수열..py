"""
백준 스택수열
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는
수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다.
물론 같은 정수가 두 번 나오는 일은 없다.

입력값 n이 나열된 수 처럼 수열이 되는지 판단.

값을 stack2에 넣고 stack2 top 값과 stack에 있는 값과 비교
"""
import sys

# 입력.
n = int(input())
stack = []
stack2 = []

string = ""
for i in range(n):
    stack.append(int(input()))

for i in range(1,n+1):
    stack2.append(i)
    string += "+"
    # 계속비교 하기 위함.
    while stack2 and stack[0] == stack2[-1]:
        # 큐
        stack.pop(0)
        # 스택
        stack2.pop()
        string += "-"

if stack2:
    print("NO")
else:
    for i in string:
        print(i)


