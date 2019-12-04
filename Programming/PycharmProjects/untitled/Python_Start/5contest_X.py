def reverse():
    num = int(input())
    if num != 0:
        reverse()
        if num ** 0.5 % 1 == 0:
            print(num, end=' ')
            return num
        return 0
    else:
        return 0


count = reverse()
if count == 0:
    print(0)
