
# 1 1 1 1
# 3를 만드는 방법
"""
                              +1
              +1                                -1
        +1            -1               +1               -1
    +1      -1    +1      -1       +1      -1      +1        -1

1) DFS로 탐색  루트가 +1일때 경우
                              -1
              -1                                +1
        -1            +1               -1               +1
    -1      +1    -1      +1       -1      +1      -1        +1

2) DFS로 탐색  루트가 -1일때 경우

1)+2)두개를 합한다.

"""

count = 0

def DFS(numbers, target, index=0):
    length = len(numbers)
    global count

    if sum(numbers) == target:
        count += 1

    if index < length:
        numbers[index] *= 1
        DFS(numbers, target, index + 1)

        numbers[index] *= -1
        DFS(numbers, target, index + 1)



    return count

def solution(numbers, target):

    return DFS(numbers, target)


print(solution([1, 1, 1, 1, 1, 1], 3))
