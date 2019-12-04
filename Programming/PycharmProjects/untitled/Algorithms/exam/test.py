n, m = map(int, input().split())
list1 = []
list2 = []
for i in range(n):
    local = list(map(int, input().split()))
    list1.append(local)
    temp = [0] * m
    list2.append(temp)
if list1[0][0] == 0 or list1[n - 1][m - 1] == 0:
    print("Impossible")
else:
    for i in range(m):
        if list1[0][i] != 0:
            list2[0][i] = 1
        else:
            break
    for i in range(n):
        if list1[i][0] != 0:
            list2[i][0] = 1
        else:
            break
    for i in range(1, n):
        for j in range(1, m):
            if list1[i][j] == 0:
                continue
            temp2 = list2[i - 1][j] + list2[i][j - 1]
            list2[i][j] = temp2
    if list2[n - 1][m - 1] == 0:
        print("Impossible")
    else:
        print(list2[n - 1][m - 1])
