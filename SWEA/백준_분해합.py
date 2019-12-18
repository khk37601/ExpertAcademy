#분해합
"""
입렫된 값보다 클 수 는 없다.
"""
n = int(input())
check = False

for i in range(1,n+1):

     total = i
     tmp_list = list(str(i))

     for j in tmp_list:
        total += int(j)

     if total == n:
         print(i)
         check = True
         break


if not check:
    print(0)

