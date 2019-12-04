def merge(list1, list2):
    i1 = 0
    i2 = 0
    tlist = []
    while i1 < len(list1) and i2 < len(list2):
        if list1[i1] <= list2[i2]:
            tlist.append(list1[i1])
            i1 += 1
        else:
            tlist.append(list2[i2])
            i2 += 1
    tlist = tlist + list1[i1:] + list2[i2:]
    return tlist


def mergeSort(list1):
    if len(list1) < 2:
        return list1
    mid = len(list1) // 2
    x = mergeSort(list1[:mid])
    y = mergeSort(list1[mid:])
    return merge(x, y)


n = int(input())
list1 = list(map(int, input().split()))
print(*mergeSort(list1))
