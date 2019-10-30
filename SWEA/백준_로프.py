import sys

n = int(input())
rope_list = []
weight_max = 0

for i in range(n):
    rope_list.append(int(input()))

# 큰수로정렬
rope_list.sort(reverse=True)
# 10 15      -> 10 , 10,15 -> 제일작은 수 * 로프 수  = 20  :2개의 줄로 들어올릴 수 있는 최대 무게.
# 19 17 9    -> 19    , 19, 17 -> 17*2 = 34/2 -> 17  19 17 9 -> 9*2 18

for i in range(len(rope_list)):

    if weight_max < rope_list[i] * (i + 1):
        weight_max = rope_list[i] * (i + 1)

print(weight_max)
