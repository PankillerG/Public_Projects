def finder2degree(num):
    if (num ** (1 / 2)) % 1 == 0:
        return num ** (1 / 2)
    else:
        return finder2degree(num - 1)


num = int(input())
counter = 1
s = ''
while counter <= 4:
    if finder2degree(num) != 0:
        s = s + ' ' + str(int(finder2degree(num)))
    num -= finder2degree(num) ** 2
    counter += 1
s = s[1:]
if num <= 0:
    print(s)
else:
    print('0')
