def move(n, x, y):
    if n == 1:
        print(1, x, y)
        return
    else:
        move(n - 1, x, y)
        print(n, x, 2)
        move(n - 1, y, x)
        print(n, 2, y)
        move(n - 1, x, y)


n = int(input())
move(n, 1, 3)
