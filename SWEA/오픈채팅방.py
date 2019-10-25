def solution(record):
    answer = []
    ID = {}

    for loop in record:
        if loop.split()[0].strip() == "Enter" or loop.split()[0].strip() == "Change":
            ID[loop.split()[1].strip()] = loop.split()[2].strip()


    for loop in record:

        if loop.split()[0].strip() == "Enter":
            answer.append(ID[loop.split()[1].strip()]+"님이 들어하였습니다.")
        elif loop.split()[0].strip() == "Leave":
            answer.append(ID[loop.split()[1].strip()] + "님이 나갔습니다.")




    return answer





s = solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])
print(s)



