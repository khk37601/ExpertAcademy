import sys

"""
mirkovC4nizCC44
C4

12ab112ab2ab
12ab

"""
string = sys.stdin.readline().strip()
boom = sys.stdin.readline().strip()


boom_length = len(boom)
loop = 0

while loop < len(string):

    if string[loop:(boom_length+loop)] == boom:
       string = string[:loop]+string[(boom_length+loop):]

       if loop-boom_length < 0:
           loop = -1
       else:
           loop -= boom_length
    loop +=1

if string:
    print(string)
else:
    print("FLUA")
