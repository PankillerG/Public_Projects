import sys
sys.setrecursionlimit(1000000)


def dfs(v1, v2):
    visited[v1][v2] = 1
    for i in range(4):
        way1 = v1 + d1[i]
        way2 = v2 + d2[i]
        if way1 >= 0 and way1 < n:
            if way2 >= 0 and way2 < m:
                if temp[way1][way2] == 1:
                    if visited[way1][way2] == 0:
                        dfs(way1, way2)


n, m = map(int, input().split())
temp = list()
visited = list()
d1 = [1, -1, 0, 0]
d2 = [0, 0, 1, -1]
for i in range(n):
    string = str(input())
    local = list()
    willuse = list()
    willuse = [0] * m
    for elem in string:
        if elem != '.':
            local.append(1)
        else:
            local.append(0)
    temp.append(local)
    visited.append(willuse)
all = 0
for v1 in range(n):
    for v2 in range(m):
        if visited[v1][v2] == 0 and \
                temp[v1][v2] == 1:
            all += 1
            dfs(v1, v2)
print(all)
