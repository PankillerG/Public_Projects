def move(n, x, y):
    if n == 0:
        return
    else:
        if y - x == 1 or y - x == -2:
            move(n - 1, x, 6 - x - y)
            print(n, x, y)
            move(n - 1, 6 - x - y, y)
        else:
            move(n - 1, x, y)
            print(n, x, 6 - x - y)
            move(n - 1, y, x)
            print(n, 6 - x - y, y)
            move(n - 1, x, y)


n = int(input())
move(n, 1, 3)

