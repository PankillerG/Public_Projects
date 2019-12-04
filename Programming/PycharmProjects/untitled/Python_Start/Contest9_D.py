number = list(map(int, input().split()))
numberCheck = set()
for i in range(len(number)):
    if number[i] not in numberCheck:
        print('NO')
        numberCheck.add(number[i])
    else:
        print('YES')
