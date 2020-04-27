import sys


def solution(n):
    count = 0
    if n < 10:
        n *= 10

    if n == (n % 10 + n // 10):
        return 1
    orgin = n
    tmp_n = 0

    while True:
        tmp_n = (n // 10 + n % 10)
        n = (n % 10*10) + tmp_n % 10
        count += 1
        if orgin == n:
            break

    return count


n = int(sys.stdin.readline().strip())
print(solution(n))
