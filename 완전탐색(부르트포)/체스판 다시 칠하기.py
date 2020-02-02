"""
백준 체스판 다시 칠하기.

첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다.
둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

"""

import sys

whiteBoard = [
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']
    ]

blackBoard = [
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'],
        ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'],
        ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
    ]


def solution(_map, board, x, y):
    # x,y는 시작 인덱스.
    count = 0
    # 8*8 범위 씩 비교
    for row in range(8):
        for col in range(8):

            if _map[row+x][col+y] != board[row][col]:
                count += 1

    return count


#입력
_map = []
n, m = map(int, sys.stdin.readline().split())

for row in range(n):
    _map.append(list(map(str,sys.stdin.readline().strip())))

answer = 9999999
# 입력한 체스판이 8*8이 넘어가는 경우가 생김.
# 그래서 -7 만큼 움직임니다.
for row in range(n-7):
    for col in range(m-7):
        w = solution(_map, whiteBoard, row, col)
        b = solution(_map, blackBoard, row, col)

        answer = min(answer, w, b)

print(answer)