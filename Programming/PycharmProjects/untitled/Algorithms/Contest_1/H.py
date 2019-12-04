def binSearchFirst(num, left, right):
    while left != right:
        now = (left + right) // 2
        if num == list1[now]:
            if now - 1 >= left and num == list1[now - 1]:
                right = now
            else:
                return now
        elif num < list1[now]:
            right = now
        else:
            left = now + 1
    return right


n, x, y = map(int, input().split())
minimal = min(x, y)
if n == 1:
    print(minimal)
else:
    list1 = [int((i // x + i // y)) for i in range(max(x, y) * (n - 1) + 1)]
    print(binSearchFirst(n - 1, 0, len(list1)) + minimal)
