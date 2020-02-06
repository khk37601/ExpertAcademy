"""
백준 양

"""
import sys

dx = [0, 0, 1, -1]
dy =[1, -1 ,0, 0]

def bfs(x, y):

    queue = []
    queue.append((x, y))
    sheep = 0
    wolf = 0

    if board[x][y] == 'o':
        sheep +=1
    elif board[x][y] == 'v':
        wolf +=1

    board[x][y] = 'x'

    while queue:
        x, y = queue.pop(0)

        for i in range(4):

            x_x = dx[i] + x
            y_y = dy[i] + y

            if x_x < r and y_y < c:
                if x_x >= 0 and y_y >= 0:
                    if board[x_x][y_y] != "#" and board[x_x][y_y] != 'x' :
                        queue.append((x_x, y_y))
                        if  board[x_x][y_y] == 'o':
                            sheep +=1
                        elif board[x_x][y_y] == 'v':
                            wolf +=1

                        board[x_x][y_y] = 'x'

    if wolf < sheep:
        return (sheep, 0)

    return (0, wolf)


r, c = map(int, sys.stdin.readline().split())
board = []
sheep = 0
wolf = 0

for row in range(r):
    board.append(list(sys.stdin.readline().strip()))


for i in range(r):
    for j in range(c):

        if board[i][j] != '#' and board[i][j] != 'x':
            count = bfs(i, j)
            sheep +=count[0]
            wolf += count[1]

print(sheep, wolf)

