def full(bin, n):
    return bin.zfill(n)


def solution(n, arr1, arr2):
    answer = []
    for x, y in zip(arr1, arr2):
        maze = ''
        bin_x, bin_y = full(format(x, 'b'), n), full(format(y, 'b'), n)
        for i, j in zip(bin_x, bin_y):
            if int(i) or int(j) == 1:
                maze += '#'
            else:
                maze += ' '
        answer.append(maze)
    return answer
