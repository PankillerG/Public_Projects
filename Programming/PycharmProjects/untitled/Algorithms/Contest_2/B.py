def move(n, x, y):
    if n == 0:
        return
    else:
        if x == 1 and y == 3:
            move(n, 1, 2)
            move(n, 2, 3)
        elif x == 3 and y == 1:
            move(n, 3, 2)
            move(n, 2, 1)
        else:
            move(n - 1, x, 6 - x - y)
            print(n, x, y)
            move(n - 1, 6 - x - y, y)


n = int(input())
move(n, 1, 3)
