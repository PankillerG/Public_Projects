n, m = map(int, input().split())
list2 = list()
list1 = list()
for i in range(n):
    local = list(map(int, input().split()))
    temp = [0] * m
    list1.append(local)
    list2.append(temp)
if list1[n - 1][m - 1] == 0 or list1[0][0] == 0:
    print("Impossible")
else:
    list2[0][0] = 1
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0:
                continue
            if list1[i][j] == 0:
                continue
            a, b = 0, 0
            if i > 0:
                a = list2[i - 1][j]
            if j > 0:
                b = list2[i][j - 1]
            list2[i][j] = a + b
    if list2[n - 1][m - 1] != 0:
        print(list2[n - 1][m - 1])
    else:
        print("Impossible")
