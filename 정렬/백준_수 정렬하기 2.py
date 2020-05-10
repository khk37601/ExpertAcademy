import sys

"""

def _sort(left, right):
    sort_list = []
    right_index = left_index = 0

    right_len = len(right)
    left_len = len(left)

    while right_index < right_len and left_index < left_len:

        if left[left_index] < right[right_index]:
            sort_list.append(left[left_index])
            left_index += 1
        else:
            sort_list.append(right[right_index])
            right_index += 1

    if left_index < left_len:
        sort_list = sort_list + left[left_index:]
    if right_index < right_len:
        sort_list = sort_list + right[right_index:]

    return sort_list


def merge(iterables):
    length = len(iterables)
    if length <= 1:
        return iterables
    mid = length//2

    left = merge(iterables[:mid])
    right = merge(iterables[mid:])

    return _sort(left, right)


n = int(sys.stdin.readline().strip())

_list = [int(sys.stdin.readline().strip()) for _ in range(n)]


print('\n'.join(map(str, merge(_list))))
"""
_list = [int(sys.stdin.readline().strip()) for _ in range(int(sys.stdin.readline().strip()))]
print("\n".join(map(str, sorted(_list))))