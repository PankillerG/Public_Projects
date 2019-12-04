def merge(n):
    i1 = 1
    i2 = 1
    total = 0
    if num > 5 * 10**6:
        i1 = 5 * 10**6
        i2 = 5 * 10**6
    while n > 0:
        i1_2 = i1**2
        i2_3 = i2**3
        if i1_2 < i2_3:
            total = i1_2
            i1 += 1
        elif i1_2 == i2_3:
            total = i1_2
            i1 += 1
            i2 += 1
        else:
            total = i2_3
            i2 += 1
        n -= 1
    return total


num = int(input())
print(merge(num))
