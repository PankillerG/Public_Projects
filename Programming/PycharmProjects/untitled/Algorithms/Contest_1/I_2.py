def squad(num):
    return (num // w) * (num // h)


def binSearchFirst(num, left, right):
    while left != right:
        now = (left + right) // 2
        if num == squad(now):
            if now - 1 >= left and num == squad(now - 1):
                right = now
            else:
                return now
        elif num < squad(now):
            right = now
        else:
            left = now + 1
    return right


w, h, n = map(int, input().split())
maximal = max(w, h)
if n == 1:
    print(maximal)
else:
    print(binSearchFirst(n, 0, max(w, h) * n))
