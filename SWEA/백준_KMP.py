

input_string = input()


# - 기준으로 문자열 분리 분리된 문자열의 첫문자만 가져와 연결한다.
print(''.join(i[0] for i in input_string.split('-')))



