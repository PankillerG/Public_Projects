def binSearch(num, left, right):
    while left != right:
        now = (left + right) // 2
        if num == list1[now]:
            return 'YES'
        elif num < list1[now]:
            right = now
        else:
            left = now + 1
    return 'NO'


n, k = map(int, input().split())
list1 = list(map(int, input().split()))
list2 = list(map(int, input().split()))
for i in range(k):
    print(binSearch(list2[i], 0, n))
