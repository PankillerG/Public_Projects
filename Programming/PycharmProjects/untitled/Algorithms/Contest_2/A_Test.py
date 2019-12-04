def move(frm, to, use, a):
    if a == 0:
        return
    else:
        move(frm, use, to, a - 1)
        print(a, frm, to)
        move(use, to, frm, a - 1)


n = int(input())
move(1, 3, 2, n)
