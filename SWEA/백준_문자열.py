input_string = input()

# 공백기준으로 분리.
front = input_string.strip().split()[0]
tail = input_string.strip().split()[1]

front_len = len(front)
tail_len = len(tail)


total = (tail_len - front_len) + 1
# 길를 front 에다가 맞추기
# tail = tail[0:front_len]
mini = 99999
# 차이만큼 반복.
for i in range(total):
    count = 0
    for j in range(front_len):
        if front[j] != tail[i+j]:
            count += 1

    if mini > count:

        mini = count

print(mini)
