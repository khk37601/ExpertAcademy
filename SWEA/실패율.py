
def solution(N, stages):

    answer = []
    stages_miss_list = []
    miss_list = {}

    for stage_number in range(1, N+1):
        succeed = 0
        non_succeed = 0
        for loop in stages:
            if stage_number < loop:
                succeed += 1
            if stage_number == loop:
                non_succeed += 1


        if succeed != 0:

                miss_list[stage_number] = non_succeed/succeed
                stages_miss_list.append(non_succeed/succeed)

        else:

            miss_list[stage_number] = non_succeed
            stages_miss_list.append(non_succeed)

    stages_miss_list.sort(reverse=True)
    del_key = 0
    print(miss_list)

    for i in stages_miss_list:
        for key, value in miss_list.items():
            if i == value:
                answer.append(key)
                del_key = key
                break

        del miss_list[del_key]


    return answer



def solution2(N, stages):
    answer = []
    miss_list = {}
    lens = len(stages)

    for loop in range(1, N+1):
        if lens != 0:
            count = stages.count(loop)
            miss_list[loop] = count / lens
            lens -= count
        else:
            miss_list[loop] = 0

    return sorted(miss_list, key=lambda x: miss_list[x], reverse=True)

s = solution2(5,[2, 1, 2, 6, 2, 4, 3, 3])
print(s)
t = [2, 1, 2, 6, 2, 4, 3, 3]
