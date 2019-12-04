n, l = map(int, input().split())
list1 = list()
for i in range(n):
    list1.append(list(map(int, input().split())))
for i in range(n):
    for j in range(i + 1, n):
        t1 = 0
        t2 = 0
        total = 0
        for k in range(l):
            if list1[i][t1] <= list1[j][t2]:
                total = list1[i][t1]
                t1 += 1
            else:
                total = list1[j][t2]
                t2 += 1
        print(total)
