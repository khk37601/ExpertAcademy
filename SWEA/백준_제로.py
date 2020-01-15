

n = int(input())
stack = []

for i in range(n):

    k = int(input())

    if k == 0:
        if stack:
            stack.pop()
    else:
        stack.append(k)

print(sum(stack))