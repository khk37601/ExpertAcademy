
import sys

for l in range(10):
    n = int(sys.stdin.readline())
    number = 666

    cnt = 0
    six_cnt = 0

    while True:
        if n == 1:
            print(number)
            break

        for i in str(number):
            if i == '6':
                six_cnt += 1
            else:
                six_cnt = 0

        if six_cnt >= 3:
            cnt += 1

        six_cnt = 0

        if cnt == n:
            print(number)
            break
        number +=1

    while n:
        if "666" in str(number):
            n -= 1
        number += 1

    print(number-1)




