def BinarySearch(arr, val, low, high):
    if low > high:
        return False

    mid = (low + high) // 2
    if arr[mid] > val:
        return BinarySearch(arr, val, low, mid - 1)
    elif arr[mid] < val:
        return BinarySearch(arr, val, mid + 1, high)
    else:
        return True


N = int(input())
A = list(map(int, input().split()))
M = int(input())
M_list = list(map(int, input().split()))
A = sorted(A)

for m in M_list:
    if BinarySearch(A, m, 0, N - 1):
        print(1)
    else:
        print(0)