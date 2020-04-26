import sys


tree = [0 for _ in range(26)]


def childes(root):
    # 왼쪽 자식
    left = tree[ord(root) - 65][1]
    # 오른쪽 자식
    right = tree[ord(root) - 65][2]

    return left, right


def is_ture(root):
    if root == '.':
        return True


# 전위 탐색
def pre_order(root):
    if is_ture(root):
        return

    left, right = childes(root)

    print(root, end="")
    pre_order(left)
    pre_order(right)


# 중우탐색
def in_order(root):

    if is_ture(root):
        return

    left, right = childes(root)

    in_order(left)
    print(root, end="")
    in_order(right)


# 우위탐색
def post_order(root):

    if is_ture(root):
        return

    left, right = childes(root)

    post_order(left)
    post_order(right)
    print(root, end="")


n = int(sys.stdin.readline().strip())

# 리스트를 이용한 트리 구조 생성.
for _ in range(n):
    sub = list(map(str, sys.stdin.readline().strip().split()))
    tree[ord(sub[0])-65] = sub


pre_order('A')
print()
in_order('A')
print()
post_order('A')