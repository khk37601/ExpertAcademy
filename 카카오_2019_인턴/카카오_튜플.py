"""
 카카오_하반기_2019_인턴 문제 2
"""

# 내 풀이
def solution(tuples):
    answer = []

    tuples = tuples[1:-1]
    tuples = eval(tuples)
    tuples = sorted(tuples)

    for element in tuples:
        if isinstance(element, int):
            answer.append(element)
        else:
            for number in element:
                if number not in answer:
                    answer.append(number)

    return answer


# 다른 사람 풀이
def solution2(tuples):
    answer = []
    tuples = tuples.lstrip("{").rstrip("}").split("},{")

    stack = []
    for loop in tuples:
        stack.append(loop.split(","))
    # 정렬
    stack = sorted(stack, key=len)
    for loop in stack:
        for loop2 in loop:
            if int(loop2) not in answer:
                answer.append(int(loop2))
                
    return answer


print(solution2("{{1,2,3},{2,1},{1,2,4,3},{2}}"))