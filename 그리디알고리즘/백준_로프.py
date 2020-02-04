"""
백준 로프
로프를 이용하여 이런 저런 물체를 들어올릴 수 있다. 각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는
물체의 중량이 서로 다를 수도 있다.

하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다.
k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게
 w/k 만큼의 중량이 걸리게 된다.

임의로 몇 개의 로프를 골라서 사용해도 된다. 단, 각각의 로프는 한 개씩만 존재한다.

"""
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

print(weight_max, 9*3)
