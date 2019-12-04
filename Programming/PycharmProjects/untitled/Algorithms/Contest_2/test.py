def move(frm, to, a):
    temp = 6 - (frm + to)
    f1 = (to - frm) == 1
    f2 = (to - frm) == -2
    if a == 0:
        return
    else:
        if f1 or f2:
            move(frm, temp, a - 1)
            print(a, frm, to)
            move(temp, to, a - 1)
        else:
            move(frm, to, a - 1)
            print(a, frm, temp)
            move(to, frm, a - 1)
            print(a, temp, to)
            move(frm, to, a - 1)


n = int(input())
move(1, 3, n)