def binSearchFirst(num, left, right):
    while left != right:
        now = (left + right) // 2
        if num == list1[now]:
            if now - 1 >= left and num == list1[now - 1]:
                right = now
            else:
                return now + 1
        elif num < list1[now]:
            right = now
        else:
            left = now + 1
    return now


list1 = list(map(int, input().split()))
print()
print(binSearchFirst(4, 0, 3))
