def merge(list1, list2, list3):
    i1 = 0
    i2 = 0
    i3 = 0
    tlist = []
    while i1 < len(list1) and i2 < len(list2) and i3 < len(list3):
        if list1[i1] <= list2[i2] and list1[i1] <= list3[i3]:
            tlist.append(list1[i1])
            i1 += 1
        elif list2[i2] <= list1[i1] and list2[i2] <= list3[i3]:
            tlist.append(list2[i2])
            i2 += 1
        elif list3[i3] <= list2[i2] and list3[i3] <= list1[i1]:
            tlist.append(list3[i3])
            i3 += 1
    while i1 < len(list1) and i2 < len(list2):
        if list1[i1] <= list2[i2]:
            tlist.append(list1[i1])
            i1 += 1
        else:
            tlist.append(list2[i2])
            i2 += 1
    while i1 < len(list1) and i3 < len(list3):
        if list1[i1] <= list3[i3]:
            tlist.append(list1[i1])
            i1 += 1
        else:
            tlist.append(list3[i3])
            i3 += 1
    while i2 < len(list2) and i3 < len(list3):
        if list2[i2] <= list3[i3]:
            tlist.append(list2[i2])
            i2 += 1
        else:
            tlist.append(list3[i3])
            i3 += 1
    tlist = tlist + list1[i1:] + list2[i2:] + list3[i3:]
    return tlist


n, m, k = map(int, input().split())
list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))
list3 = list(map(int, input().split()))
print(*merge(list1, list2, list3))
