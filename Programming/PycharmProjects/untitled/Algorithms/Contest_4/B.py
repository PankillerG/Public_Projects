import random


def quickSort(a):
    if len(a) < 2:
        return a
    p = random.choice(a[0: len(a) - 1])
    listLess = [i for i in a if i < p]
    listMiddle = [p] * a.count(p)
    listMore = [i for i in a if i > p]
    return quickSort(listLess) + listMiddle + quickSort(listMore)


n = int(input())
list1 = list(map(int, input().split()))
list1 = quickSort(list1)
print(*list1)
