def merge(num):
    i1 = 1
    i2 = 1
    i1_2 = i1 ** 2
    i2_3 = i2 ** 3
    tlist = []
    for i in range(num):
        if i2_3 < i1_2:
            tlist.append(i2_3)
            i2 += 1
            i2_3 = i2 ** 3
        elif i1_2 == i2_3:
            tlist.append(i1_2)
            i1 += 1
            i2 += 1
            i1_2 = i1 ** 2
            i2_3 = i2 ** 3
        else:
            tlist.append(i1_2)
            i1 += 1
            i1_2 = i1 ** 2
    return tlist[num - 1]


num = int(input())
print(merge(num))
