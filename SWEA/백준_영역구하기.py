import sys
import collections


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]


def dfs(m, n,end_x, end_y, bord):

    visit = [(m,n)]
    cnt = 1
    while visit:

        x, y = visit.pop(0)
        for i in range(4):

            x_x = dx[i] + x
            y_y = dy[i] + y

            if (x_x >= 0 and y_y >= 0 ) and x_x < end_x  and y_y < end_y  and bord[x_x][y_y] == 0:
                  cnt += 1
                  bord[x_x][y_y] = 'x'
                  visit.append((x_x, y_y))

    if cnt > 1:
        cnt -=1

    return cnt




m ,n, k= map(int, sys.stdin.readline().strip().split())




visit = [[0]*n for i in range(m)]
bord =[[0]*n for i in range(m)]
count_list = []
for i in range(k):
     x1, y1, x2, y2= map(int, sys.stdin.readline().strip().split())

     for i in range(x1,x2):
            for j in range(y1,y2):
                bord[j][i] = 'x'


for i in range(m):
    for j in range(n):
        if bord[i][j] == 0 and visit[i][j] == 0:
            visit[i][j] +=1
            count_list.append(dfs(i, j, m, n, bord))

print(len(count_list))
print(' '.join(str(i) for i in sorted(count_list)))

