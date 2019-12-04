n, w, l = map(int, input().split())
places = []
for i in range(n):
    x1, y1, z1, x2, y2, z2 = map(int, input().split())
    places.append((z1, 1, (x2 - x1) * (y2 - y1), i + 1))
    places.append((z2, -1, (x2 - x1) * (y2 - y1), i + 1))
minimum = 10 ** 6
summ = 0
count = 0
places = sorted(places, key=lambda x: (x[0], x[1]))
for i in range(n * 2):
    summ += places[i][1] * places[i][2]
    count += places[i][1]
    if summ == w * l and count < minimum:
        minimum = count
        j = i
if minimum == 10 ** 6:
    print('NO')
else:
    print('YES')
    print(minimum)
    all = [0] * n
    for i in range(j + 1):
        all[places[i][3] - 1] += places[i][1]
    for i in range(n):
        if all[i] == 1:
            print(i + 1)
