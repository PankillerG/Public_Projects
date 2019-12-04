def countNeigh(i, j):
    count = 0
    if 0 <= i - 1 < n and 0 <= j - 1 < n:
        count += w[i - 1][j - 1]
    if 0 <= i - 1 < n and 0 <= j < n:
        count += w[i - 1][j]
    if 0 <= i - 1 < n and 0 <= j + 1 < n:
        count += w[i - 1][j + 1]
    if 0 <= i < n and 0 <= j - 1 < n:
        count += w[i][j - 1]
    if 0 <= i < n and 0 <= j + 1 < n:
        count += w[i][j + 1]
    if 0 <= i + 1 < n and 0 <= j - 1 < n:
        count += w[i + 1][j - 1]
    if 0 <= i + 1 < n and 0 <= j < n:
        count += w[i + 1][j]
    if 0 <= i + 1 < n and 0 <= j + 1 < n:
        count += w[i + 1][j + 1]
    return count


n, t = map(int, input().split())
w = []
w2 = []
for i in range(n):
    string = list(map(int, input().split()))
    w.append(string)
w2 = w
for k in range(1, t):
    for i in range(n):
        for j in range(n):
            count = countNeigh(i, j)
            if count < 2:
                w2[i][j] = 0
            if count == 2:
                w2[i][j] = w[i][j]
            if count == 3:
                w2[i][j] = 1
            if count > 3:
                w2[i][j] = 0
    w = w2
for i in range(n):
    for j in range(n):
        print(w[i][j], end=' ')
    print()
