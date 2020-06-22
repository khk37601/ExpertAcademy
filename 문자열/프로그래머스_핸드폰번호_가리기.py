def solution(phone_number):
    phone_number = list(phone_number) 

    for index, value in enumerate(phone_number[:-4]) :
     	phone_number[index] = '*'   
    return ''.join(phone_number)

print(solution("027778888"))