def move(n, x, y):
    if n == 0:
        return
    else:
        move(n - 1, x, 6 - x - y)
        print(n, x, y)
        move(n - 1, 6 - x - y, y)


n = int(input())
if n % 2 == 0:
    move(n, 1, 3)
    n -= 1
else:
    move(n, 1, 2)
    n -= 1
while n > 0:
    if n % 2 == 0:
        move(n, 2, 3)
        n -= 1
    else:
        move(n, 3, 2)
        n -= 1
