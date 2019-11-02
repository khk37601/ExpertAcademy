def solution(s):
    answer = len(s) % 2
    index = len(s) // 2
    #길이가 홀수 짝수 구별
    if answer > 0:
        return s[index]
    else:
        return s[index-1:index+1]

#다른 사람 풀이법.
def string_middle(str):
    # 함수를 완성하세요

    return str[(len(str)-1)//2:len(str)//2+1]