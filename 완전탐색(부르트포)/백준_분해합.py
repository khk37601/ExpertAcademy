"""
백준 분해합.

245의 분해합은 256(=245+2+4+5)이 된다. 따라서 245는 256의 생성자가 된다.
물론, 어떤 자연수의 경우에는 생성자가 없을 수도 있다. 반대로, 생성자가 여러 개인 자연수도 있을 수 있다.

첫째 줄에 자연수 N(1 ≤ N ≤ 1,000,000)이 주어진다.

"""
import sys

# 입력
n = int(sys.stdin.readline())
answer = 0
"""
    생성자는 입력값을 넘을 수 없음.
    생성자 <= n
"""

for loop in range(1,n):
    _sum = 0

    for loop2 in str(loop):
        _sum += int(loop2)

    if (_sum + int(loop)) == n:
        answer = loop
        break

print(answer)