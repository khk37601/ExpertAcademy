import sys

n = int(sys.stdin.readline().strip())

# 비율 구하기
for _ in range(n):
    line = list(map(int, sys.stdin.readline().strip().split()))
    avg = sum(line[1:])//line[0]
    count = 0
    for element in line[1:]:
        if element > avg:
            count += 1

    print("%.3f%s" % (((count / line[0]) * 100), "%"))
