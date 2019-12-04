def merge(list1, list2):
    i1 = 0
    i2 = 0
    tlist = []
    while i1 <= len(list1) - 1 or i2 <= len(list2) - 1:
        if i1 <= len(list1) - 1 and i2 <= len(list2) - 1:
            if list1[i1] <= list2[i2]:
                tlist.append(list1[i1])
                i1 += 1
            else:
                tlist.append(list2[i2])
                i2 += 1
        elif i1 <= len(list1) - 1:
            tlist += list1[i1:]
            i1 = len(list1)
        else:
            tlist += list2[i2:]
            i2 = len(list2)
    return tlist


n = int(input())
list1 = list(map(int, input().split()))
m = int(input())
list2 = list(map(int, input().split()))
print(*merge(list1, list2))
