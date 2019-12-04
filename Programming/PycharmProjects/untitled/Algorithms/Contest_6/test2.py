import sys
sys.setrecursionlimit(1000000)


def dfs(number, b):
    global first, last
    visited[number] = 1
    for vertex in range(len(graph[number])):
        local = graph[number][vertex]
        if local == b:
            continue
        if visited[local] == 0:
            before[local] = number
            if dfs(local, number):
                return 1
        elif visited[local] == 1:
            first = local
            last = number
            return 1
        visited[number] = -1
        return 0


n = int(input())
graph = []
visited = [0] * n
before = [0] * n
for i in range(n):
    graph.append([])
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(n):
        if a[j] == 1:
            graph[i].append(j)
first = None
last = None
for vertex in range(n):
    if dfs(vertex, vertex):
        break
if first is None:
    print('NO')
else:
    print('YES')
    all = list()
    all.append(1 + last)
    while first != last:
        last = before[last]
        all.append(1 + last)
    print(len(all))
    print(*all)

