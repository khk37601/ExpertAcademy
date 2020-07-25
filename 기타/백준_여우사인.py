import sys

FOX_MOTION = {'1': 0, '2': 0, '3': 0, '4': 0, '5': 0}
TOW = 2


def solution(pair):
    if pair['x'] in FOX_MOTION.keys():
        FOX_MOTION[pair['x']] += 1
    if pair['y'] in FOX_MOTION.keys():
        FOX_MOTION[pair['y']] += 1


def result():
    if FOX_MOTION['1'] == TOW and FOX_MOTION['3'] == TOW and FOX_MOTION['4'] == TOW:
        print('Wa-pa-pa-pa-pa-pa-pow!')
    else:
        print('Woof-meow-tweet-squeek')


for i in range(int(sys.stdin.readline().strip())):
    x, y = sys.stdin.readline().split()
    solution({'x': x, 'y': y})

result()

