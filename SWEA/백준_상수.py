
input_string = input()

number1 = input_string.strip().split()[0]
number2 = input_string.strip().split()[1]

if number1[::-1] < number2[::-1]:
    print(number2[::-1])
else:
    print(number1[::-1])