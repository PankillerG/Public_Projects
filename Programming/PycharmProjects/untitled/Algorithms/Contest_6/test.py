import sys


def dfs(v, p):
    global st
    global en
    vis[v] = 1
    for i in range(len(g[v])):
        to = g[v][i]
        if to == p:
            continue
        if vis[to] == 0:
            parent[to] = v
            if dfs(to, v):
                return 1
        elif vis[to] == 1:
            st = to
            en = v
            return 1
    vis[v] = 2
    return 0


sys.setrecursionlimit(1000000)
n = int(input())
g = []
st = -1
en = -1
for i in range(n):
    g.append([])
vis = [0] * 728
parent = [-1] * 728
for i in range(n):
    ml = list(map(int, input().split()))
    for j in range(n):
        if ml[j] == 1:
            g[i].append(j)

for i in range(n):
    if dfs(i, i):
        break
if st == -1:
    print("NO")
else:
    print("YES")
    ans = []
    ans.append(en + 1)
    while en != st:
        en = parent[en]
        ans.append(en + 1)
    print(len(ans))
    print(*ans)
