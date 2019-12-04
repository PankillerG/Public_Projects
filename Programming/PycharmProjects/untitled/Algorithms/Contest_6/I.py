n, m, s, t, q = map(int, input().split())
s, t = s - 1, t - 1
place, livers, willuse = list(), list(), list()
willuse.append([s, t])
c_livers = 0
flag = False
for i in range(n):
    place.append([])
    for j in range(m):
        place[i].append(-1)
place[s][t] = 0
for i in range(q):
    local = list(map(int, input().split()))
    local[0], local[1] = local[0] - 1, local[1] - 1
    livers.append(local)

while len(willuse) != 0:
    a, b = willuse[0][0], willuse[0][1]
    for i in range(-1, 2, 2):
        for j in range(-2, 3, 4):
            if 0 <= a + i < n and \
                    0 <= b + j < m and \
                    place[a + i][b + j] == -1:
                place[a + i][b + j] = place[a][b] + 1
                willuse.append([a + i, b + j])
            if 0 <= a + j < n and \
                    0 <= b + i < m and \
                    place[a + j][b + i] == -1:
                place[a + j][b + i] = place[a][b] + 1
                willuse.append([a + j, b + i])
    temp = willuse[0]
    willuse.remove(temp)
for i in livers:
    if place[i[0]][i[1]] != -1:
        c_livers = c_livers + place[i[0]][i[1]]
    else:
        flag = True
if not flag:
    print(c_livers)
else:
    print(-1)
