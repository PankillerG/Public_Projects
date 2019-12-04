n, m = map(int, input().split())
list1 = list(map(int, input().split()))
list1 = sorted(list1)
summ = 0
count = 0
i = 0
for elem in list1:
    if summ + elem <= n:
        count += 1
        summ += elem
print(count)
