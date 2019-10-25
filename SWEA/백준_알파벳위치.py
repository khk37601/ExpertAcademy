
input_string = input()
dic_list = {}
#-1로 초기화
alphabet = [-1 for i in range(26)]
#
string = ""

# 알파벳 인덱스
for i, j in enumerate(input_string):
    # 덮혀 쓰기 방지.
    if j in dic_list.keys():
        continue
    dic_list[j] = i

# 알파벳위치한  인덱스
for i, j in dic_list.items():
    # 문장을 int형으로 변환.
    alphabet[ord(i) - 97] = j

for i in alphabet:
    string += ''.join(str(i))+' '

print(string)
