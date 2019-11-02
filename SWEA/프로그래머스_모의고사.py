def solution(answers):
    student_list = {0: "12345", 1: "21232425", 2: "3311224455"}
    answer = []
    student_number = []

    for loop in range(3):
        count = 0

        while len(student_list[loop]) < len(answers):
            student_list[loop] *= 2

        student_answer = list(student_list[loop])

        for loop2 in range(0, len(answers)):
            if answers[loop2] == int(student_answer[loop2]):
                count += 1

        answer.append(count)

    max_s = max(answer)

    if answer.count(max_s) >= 3:
        return [1, 2, 3]
    else:
        for loop in range(len(answer)):
            if max_s == answer[loop]:
                student_number.append(loop + 1)

    return student_number