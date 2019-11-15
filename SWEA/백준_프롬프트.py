
n = int(input())
string_list = []

for i in range(n):
    string_list.append(input())

eq = list(string_list[0])

for i in string_list[1:]:
    for j in range(len(i)):
        if eq[j] != i[j]:
            eq[j] = '?'


print(''.join(eq))