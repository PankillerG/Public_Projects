a, b = int(input()), int(input())
for i in range(a, b + 1):
    j = str(i)
    c1, c2, c3, c4 = j[0], j[1], j[2], j[3]
    if c1 == c2 and c1 == c3 and c2 == c3 and c1 != c4:
        print(i)
    if c1 == c3 and c1 == c4 and c3 == c4 and c1 != c2:
        print(i)
    if c2 == c3 and c2 == c4 and c3 == c4 and c1 != c2:
        print(i)
    if c1 == c2 and c1 == c4 and c2 == c4 and c1 != c3:
        print(i)
