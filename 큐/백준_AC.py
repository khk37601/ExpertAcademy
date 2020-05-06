"""


import sys

t = int(sys.stdin.readline().strip())

for _ in range(t):
    command_line = sys.stdin.readline().strip()
    arr_length = int(sys.stdin.readline().strip())
    try:
        arr = list(map(int, sys.stdin.readline()[1:-2].strip().split(",")))
    except:
        print("error")
    else:
        check = False
        # command_line = command_line.replace("RR", "")
        is_reverse = False

        for command in command_line:
            if not arr:
                check = True
                break
            if command == "R":
                is_reverse = not is_reverse
            elif command == "D":
                if arr:
                    if is_reverse:
                        arr.pop()
                    else:
                        arr.pop(0)
                else:
                    check = True
                    break
        if check:
            print("error")
        else:
            if is_reverse:
                arr.reverse()

            print("[", end="")
            print(",".join(map(str, arr)), end="")
            print("]")

"""
# 다른 사람 풀이
import re
import sys
from collections import deque

t = int(sys.stdin.readline())

for _ in range(t):
    command_line = list(sys.stdin.readline())
    arr_length = int(sys.stdin.readline())
    arr = sys.stdin.readline()
    arr = re.split("\[|\]|,|\n", arr)
    arr = deque(arr[1:-2])

    if arr_length == 0:
        arr = deque([])

    is_reverse = False
    check = False
    oob = False
    for command in command_line:
        if command == "R":
            is_reverse = not is_reverse
        elif command == "D":
            if len(arr) == 0:
                check = True
                break
            if is_reverse:
                arr.pop()
            else:
                arr.popleft()

    if check:
        print("error")
    else:
        arr = list(arr)
        if is_reverse:
            arr.reverse()

        print("[", end="")
        print(",".join(arr), end="")
        print("]")
