n = int(input())
listall = list()
for i in range(n):
    a, b = map(int, input().split())
    listall.append([a, 1, i + 1])
    listall.append([b, 0, i + 1])
listall = sorted(listall, key=lambda x: (x[0], x[1]))
m = 10 ** 10
left = 0
right = 0
now = 0
for i in range(len(listall) - 1):
    if listall[i][1] == 1:
        now += 1
    if listall[i + 1][1] == 0 and listall[i][1] == 1 and \
            listall[i][2] != listall[i + 1][2] and \
            0 < listall[i + 1][0] - listall[i][0] < m:
        m = listall[i + 1][0] - listall[i][0]
        left = listall[i][2]
        right = listall[i + 1][2]
    elif listall[i + 1][1] == 0 and listall[i][1] == 1 and \
            listall[i][2] == listall[i + 1][2] and now > 1 and \
            0 < listall[i + 1][0] - listall[i][0] < m:
        j = i + 2
        while listall[j][1] == 1:
            j += 1
        m = listall[i + 1][0] - listall[i][0]
        left = listall[i][2]
        right = listall[j][2]
    if listall[i][1] == 0:
        now -= 1
if m != 10 ** 10:
    if left <= right:
        print(left, right)
    else:
        print(right, left)
else:
    print(0)
