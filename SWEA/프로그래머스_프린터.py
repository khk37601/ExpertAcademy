def solution(priorities, location):
    arr = []
    count = 0
    for index, priorty in enumerate(priorities):
        arr.append((priorty, index))

    while arr:
        if len(arr) <= 1:
            count += 1
            break;
        prior, index = arr[0]
        del arr[0]

        max_prior, max_index = max(arr)
        if max_prior > prior:
            arr.append((prior, index))
        else:
            count += 1
            if index == location:
                break

    return count