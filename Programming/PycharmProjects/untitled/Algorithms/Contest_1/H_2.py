def papers(num):
    return num // x + num // y


def binSearchFirst(num, left, right):
    while left != right:
        now = (left + right) // 2
        if num == papers(now):
            if now - 1 >= left and num == papers(now - 1):
                right = now
            else:
                return now
        elif num < papers(now):
            right = now
        else:
            left = now + 1
    return right


n, x, y = map(int, input().split())
minimal = min(x, y)
if n == 1:
    print(minimal)
else:
    print(binSearchFirst(n - 1, 0, max(x, y) * (n - 1) + 1) + minimal)
