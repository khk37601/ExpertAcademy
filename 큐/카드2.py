from collections import deque

n = int(input())

queue = deque([i for i in range(1, n+1)])
#queue = [i for i in range(1, n+1)]


while True:

    if len(queue) <= 1:
        print(queue.pop())
        break

    queue.popleft()
    queue.append(queue.popleft())









