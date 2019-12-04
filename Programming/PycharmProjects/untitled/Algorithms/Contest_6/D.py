import sys
sys.setrecursionlimit(1000000)


def dfs(num, bef):
    global first, last
    visited[num] = 1
    for i in range(len(graph[num])):
        local = graph[num][i]
        if local == bef:
            continue
        if visited[local] == 0:
            before[local] = num
            if dfs(local, num):
                return 1
        elif visited[local] == 1:
            first = local
            last = num
            return 1
    visited[num] = -1
    return 0


n = int(input())
graph = []
for i in range(n):
    graph.append([])
visited = [0] * n
before = [-1] * n
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(n):
        if a[j] == 1:
            graph[i].append(j)
first = ''
last = ''
for ver in range(n):
    if dfs(ver, ver):
        break
if first == '':
    print("NO")
else:
    print("YES")
    all = list()
    all.append(1 + last)
    while last != first:
        last = before[last]
        all.append(last + 1)
    print(len(all))
    print(*all)

