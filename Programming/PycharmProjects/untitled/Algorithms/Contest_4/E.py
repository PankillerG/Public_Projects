def length(x, y, dist, xlow, ylow):
    if str(x) + ' ' + str(y) not in place:
        dist1 = 0
        for i in cities:
            dist1 = dist1 + abs(
                x - int(i[:i.find(' ')])) + abs(
                y - int(i[i.find(' ') + 1:]))
        if dist == 0 or dist > dist1:
            dist = dist1
            xlow = x
            ylow = y
    return xlow, ylow, dist


def search(x0, x1, y0, y1):
    for x in range(x0, x1):
        for y in range(y0, y1):
            if str(x) + ' ' + str(y) not in place:
                return x, y
    dist = 0
    xlow = 0
    ylow = 0
    for i in cities:
        xlow, ylow, dist = length(
            int(i[:i.find(' ')]) + 1, int(
                i[i.find(' ') + 1:]),
            dist, xlow, ylow)
        xlow, ylow, dist = length(
            int(i[:i.find(' ')]), int(
                i[i.find(' ') + 1:]) + 1,
            dist, xlow, ylow)
        xlow, ylow, dist = length(
            int(i[:i.find(' ')]) - 1, int(
                i[i.find(' ') + 1:]),
            dist, xlow, ylow)
        xlow, ylow, dist = length(
            int(i[:i.find(' ')]), int(
                i[i.find(' ') + 1:]) - 1,
            dist, xlow, ylow)
    return xlow, ylow


n = int(input())
cities = []
for i in range(n):
    cities.append(input())
place = set(cities)
l = len(cities)
if l > 1 and l % 2 == 0:
    cities = sorted(cities, key=lambda x: int(x[:x.find(' ')]))
    x0 = int(cities[l // 2 - 1][:cities[l // 2 - 1].find(' ')])
    x1 = int(cities[l // 2][:cities[l // 2].find(' ')])
    cities = sorted(cities, key=lambda x: int(x[x.find(' ') + 1:]))
    y0 = int(cities[l // 2 - 1][cities[l // 2 - 1].find(' ') + 1:])
    y1 = int(cities[l // 2][cities[l // 2].find(' ') + 1:])
    print(*search(x0, x1, y0, y1))
elif l == 1:
    print(int(cities[0][:cities[0].find(' ')]),
          int(cities[0][cities[0].find(' ') + 1:]) + 1)
else:
    cities = sorted(cities, key=lambda x: int(x[:x.find(' ')]))
    x0 = int(cities[l // 2][:cities[l // 2].find(' ')])
    cities = sorted(cities, key=lambda x: int(x[x.find(' ') + 1:]))
    y0 = int(cities[l // 2][cities[l // 2].find(' ') + 1:])
    print(*search(x0, x0, y0, y0))
