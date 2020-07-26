import sys

WORD_START = 0
CONTENTS_START = 2


def solution(pair):
    # case 1
    print(pair['word'], pair['contents'].lower().count(pair['word']))
    # case 2
    # count = 0
    # for word in pair['contents'].lower():
    #     if pair['word'] == word:
    #         count += 1
    # print(pair['word'], count)


def main():
    is_true = True
    while is_true:
        line = sys.stdin.readline().strip()
        if line[0] != '#':
            solution({'word': line[WORD_START], 'contents': line[CONTENTS_START:]})
        else:
            is_true = False


if __name__ == '__main__':
    main()
