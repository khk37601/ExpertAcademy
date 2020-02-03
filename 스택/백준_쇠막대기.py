"""
백준 쇠막대기

한 줄에 쇠막대기와 레이저의 배치를 나타내는 괄호 표현이 공백없이 주어진다.
 괄호 문자의 개수는 최대 100,000이다.

 레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘( ) ’ 으로 표현된다. 또한, 모든 ‘( ) ’는 반드시 레이저를 표현한다.
쇠막대기의 왼쪽 끝은 여는 괄호 ‘ ( ’ 로, 오른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다.

초등부 문제....

"""
import sys

string = sys.stdin.readline().strip()
stack = []
# () => 레이저를 다른 문자로 변경한다.
string = string.replace('()', '*')
count = 0

for i in string:
    if i == '(':
        stack.append(i)
        count +=1
    else:
        if i == ')':
            stack.pop()
        else:
            count += len(stack)

print(count)