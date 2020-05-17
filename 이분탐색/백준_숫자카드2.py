import sys

san_gun = int(sys.stdin.readline().strip())
san_gun_list = list(map(int, sys.stdin.readline().strip().split()))

tmp = int(sys.stdin.readline().strip())
tmp_list = list(map(int, sys.stdin.readline().strip().split()))

dic = {}

for loop in san_gun_list:
    if loop in dic:
        dic[loop] += 1
    else:
        dic[loop] = 1

print(' '.join(str(dic[i]) if i in dic else '0' for i in tmp_list))
