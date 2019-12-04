def finder3degree(num):
    if (num ** (1 / 3)) % 1 == 0:
        return num
    else:
        return finder3degree(num - 1)


num = int(input())
counter = 1
s = ''
while counter <= 7:
    if finder3degree(num) != 0:
        s = s + ' ' + str(finder3degree(num))
    num -= finder3degree(num)
    counter += 1
s = s[1:]
if num <= 0:
    print(s)
else:
    print('0')
