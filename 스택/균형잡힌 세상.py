import sys

while True:

    input_str = input()
    if input_str == '.':
        break

    stack = []
    flag = True

    for i in input_str:
        if i in ['(', '[']:
            stack.append(i)

        elif i == ')':
                if not stack:
                    flag = False
                    break
                if stack[-1] == '(':
                    stack.pop()
                else:
                    flag = False
                    break

        elif i == ']':

            if not stack:
                flag = False
                break
            if stack[-1] == '[':
                stack.pop()
            else:
                flag = False
                break

    if not stack and flag:
        print("yes")
    else:
        print("no")


