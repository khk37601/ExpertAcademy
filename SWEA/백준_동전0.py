n, k = input().strip().split()

coin_list = []

for i in range(int(n)):
    coin_list.append(int(input()))

money = int(k)
count = 0

for i in coin_list[::-1]:
    count += money // i
    # 잔돈
    money = money % i

print(count)
