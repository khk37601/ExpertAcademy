"""
백준 양치기꿍

입력의 첫 번째 줄에는 각각 영역의 세로와 가로의 길이를 나타내는
두 개의 정수 R, C (3 ≤ R, C ≤ 250)가 주어진다.

다음 각 R줄에는 C개의 문자가 주어지며 이들은 위에서 설명한 기호들이다

k = 양
v = 늑대

6 6
...#..
.##v#.
#v.#.#
#.k#.#
.###.#
...###

=> 0 2
"""
import sys

dx = [0, 0, 1, -1]
dy = [1, -1 ,0, 0]

def bfs(x, y):

    queue = [(x, y)]
    sheep = wolf = 0

    if board[x][y] == 'k':
        sheep +=1
    elif board[x][y] == 'v':
        wolf +=1

    board[row][col] = 'x'

    while queue:
        x, y = queue.pop(0)

        for i in range(4):
            x_x = dx[i] + x
            y_y = dy[i] + y

            if x_x >=0 and y_y >=0:
                if x_x < n and y_y < m:
                    if board[x_x][y_y] != '#' and board[x_x][y_y] != 'x':

                        queue.append((x_x, y_y))

                        if board[x_x][y_y] == 'k':
                            sheep +=1
                        elif board[x_x][y_y] == 'v':
                            wolf +=1

                        board[x_x][y_y] = 'x'

    if wolf < sheep:
        return (sheep, 0)

    return (0, wolf)



n, m = map(int, sys.stdin.readline().strip().split())
board = []
wolf = sheep = 0

for i in range(n):
    board.append(list(sys.stdin.readline().strip()))


for row in range(n):
    for col in range(m):

        if board[row][col] != '#' and board[row][col] != 'x':
            count = bfs(row, col)
            wolf += count[1]
            sheep +=count[0]

print(sheep, wolf)



