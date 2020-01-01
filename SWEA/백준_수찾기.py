import sys


n = int(sys.stdin.readline())
m = list(map(int, sys.stdin.readline().split()))

n_1 = int(sys.stdin.readline())
m_1 = list(map(int, sys.stdin.readline().split()))


sort_m = sorted(m)

left = 0
right = len(m_1)-1

for i in m_1:
    left = 0
    right = len(m_1) - 1
    check = False
    while left <= right:

        mid = (left+right)//2

        if sort_m[mid] == i:
            print(1)
            check = True
            break

        if sort_m[mid] > i:
                right = mid-1
        elif sort_m[mid] < i:
                left = mid+1

    if not check:
        print(0)











