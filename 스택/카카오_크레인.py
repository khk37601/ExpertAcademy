"""
2019 카카오 개발자 겨울 인터십 1번 문제
"""
def solution(board, moves):
    answer = 0
    stack = []

    for index in moves:
        # 한 행씩
        for row in board:
            value = row[index - 1]
            # 값이 존해하는 경우만 stack에 저장.
            if value != 0:
                stack.append(value)
                # 해당 인데스 0 표시
                row[index - 1] = 0
                break
            # 인형이 없는 경우
            else:
                continue

        if len(stack) >= 2:
            if stack[-1] == stack[-2]:
                answer += 2
                stack.pop()
                stack.pop()

    return answer
solution([[0,0,0,0,0], [0,0,1,0,3], [0,2,5,0,1], [4,2,4,4,2], [3,5,1,3,1]], [1,5,3,5,1,2,1,4])