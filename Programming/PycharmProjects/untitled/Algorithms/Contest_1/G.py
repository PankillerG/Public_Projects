def binSearchFirst(num, left, right):
    while left != right:
        now = (left + right) // 2
        if num == list1[now]:
            if now - 1 >= left and num == list1[now - 1]:
                right = now
            else:
                return now + 1
        elif num < list1[now]:
            right = now
        else:
            left = now + 1
    return 'NO'


def binSearchLast(num, left, right):
    while left != right:
        now = (left + right) // 2
        if num == list1[now]:
            if now + 2 <= right and num == list1[now + 1]:
                left = now
            else:
                return now + 1
        elif num < list1[now]:
            right = now
        else:
            left = now + 1
    return 'NO'


n = int(input())
list1 = list(map(int, input().split()))
m = int(input())
list2 = list(map(int, input().split()))
for i in range(m):
    first = binSearchFirst(list2[i], 0, n)
    if first != 'NO':
        last = binSearchLast(list2[i], 0, n)
        print(first, last)
    else:
        print(0, 0)
