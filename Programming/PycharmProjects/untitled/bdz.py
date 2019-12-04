nGroup = 187
nStud = 7
first, second = map(int, input().split())
for number_now in range(first, second + 1):
    number = (number_now - 1) * 300 + (nGroup - 183) * 35 + nStud
    print(number_now, ": ", number, sep="")
