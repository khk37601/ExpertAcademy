import sys

"""
mirkovC4nizCC44
C4

12ab112ab2ab
12ab

"""
string = sys.stdin.readline().strip()
boom = sys.stdin.readline().strip()


stack = []
is_ture = False

for loop in string:
    stack.append(loop)

    stack_len = len(stack)
    boom_len = len(boom)
    # 두개의 끝 문자가 같을 경우.
    # python은 -1로 배열의 끝을 확인 할 수 있음
    # 다른 언어로도 풀수 있는 방법으로 취함.
    if stack[stack_len-1] == boom[boom_len-1]:
        # stack 에 담겨져있는 제일 끝 문자열 비교 하기 위함.
        index = stack_len - 1
        # 뒤로 부터 검사하는 이유는 112ab  : 12ab를 맞취기 위함.
        for loop2 in range(len(boom)-1, -1, -1):
            #boom 문자와 일치하는지 확인.
            if stack[index] == boom[loop2]:
                is_ture = True
                index -= 1
            else:
                is_ture = False
                break
        # 모든 문자가 일치 하는 경우
        if is_ture:
            # 문자열 크기 만큼 stack에서 뺴준다.
            for inner_loop in boom:
                stack.pop()

if stack:
    print("".join(stack))
else:
    print("FRULA")
