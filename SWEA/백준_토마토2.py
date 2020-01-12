import sys
import collections


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(n,m,bord):

    result = 0
    tomato_list= []


    for i in range(n):
        for j in range(m):
            #토마토 좌표 저장
            if bord[i][j] == 1:
                tomato_list.append((i, j))


    while tomato_list:
        result +=1
        tomato_list_len = len(tomato_list)

        # 토마토 있는 만큼
        for _ in range(tomato_list_len):
            x, y = tomato_list.pop(0)

            for i in range(4):
                x_x = dx[i] + x
                y_y = dy[i] + y

                if (x_x >= 0 and y_y >= 0) and (x_x < n and y_y < m) and bord[x_x][y_y] == 0:
                    bord[x_x][y_y] = 1
                    #새로운 토마토 좌표저장.
                    tomato_list.append((x_x, y_y))


    # 모든 토마토가 익었는지 확인.
    for i in range(n):
        for j in range(m):
            if bord[i][j] == 0:
                return -1


        return result


m, n = map(int, sys.stdin.readline().strip().split())

bord = []

for i in range(n):
    bord.append(list(map(int, sys.stdin.readline().strip().split())))


print(bfs(n,m,bord)-1)











