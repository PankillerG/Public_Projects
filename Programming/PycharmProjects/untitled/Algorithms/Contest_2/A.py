def move(n, x, y):
    if n == 0:
        return
    else:
        move(n - 1, x, 6 - x - y)
        print(n, x, y)
        move(n - 1, 6 - x - y, y)


n = int(input())
move(n, 1, 3)
