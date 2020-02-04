"""
백준 거스름돈

입력은 한줄로 이루어져있고, 타로가 지불할 돈(1 이상 1000미만의 정수) 1개가 쓰여져있다.

"""
import sys

money = 1000
coin = [500, 100, 50, 10, 5, 1]
my_money = int(sys.stdin.readline().strip())
money -= my_money
count =0

for i in coin:
    count += money // i
    money = money % i

print(count)