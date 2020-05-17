import sys

n = int(sys.stdin.readline().strip())
score = list(map(int, sys.stdin.readline().strip().split()))
score = sorted(score)

avg = 0

for loop in score:
    avg += loop/score[-1]*100

print(avg/n)

