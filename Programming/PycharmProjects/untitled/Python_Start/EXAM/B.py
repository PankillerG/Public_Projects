point = []
n, m = int(input()), int(input())
for i in range(0, m):
    s = input().split()
    coords = [*map(int, s[1:])]
    point.append((s[0], coords))
all = []
for i in range(0, m):
    for j in range(0, m):
        for z in range(0, m):
            if i != j and j != z and i != z:
                a = point[i][1]
                b = point[j][1]
                c = point[z][1]
                vector1 = [*map(lambda x: x[1] - x[0], zip(a, b))]
                vector2 = [*map(lambda x: x[1] - x[0], zip(b, c))]
                if sum(map(lambda y: y[0] * y[1], zip(vector1, vector2))) == 0:
                    pointSet = {point[i][0], point[j][0], point[z][0]}
                    if pointSet not in all:
                        all.append(pointSet)
                        print(point[i][0], point[j][0], point[z][0])
