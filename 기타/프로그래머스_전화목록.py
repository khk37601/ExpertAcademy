def solution(phone_book):
    phone_book.sort()
    first, first_len = phone_book[0], len(phone_book[0])
    for loop in phone_book[1:]:
        if first == loop[:first_len]:
            return False
    return True
