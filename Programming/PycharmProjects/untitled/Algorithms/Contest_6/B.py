import sys
sys.setrecursionlimit(100000)


def dfs(number):
    local.append(number + 1)
    visited[number] = 1
    for vertex in graph[number]:
        if visited[vertex] == 0:
            dfs(vertex)


n, m = map(int, input().split())
graph = []
visited = [0] * n
components = []
for i in range(n):
    graph.append([])
for i in range(m):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)

local = []
dfs(0)
components.append(local)
for vertex in range(len(visited)):
    if visited[vertex] == 0:
        local = []
        dfs(vertex)
        components.append(local)
print(len(components))
for i in range(len(components)):
    print(len(components[i]))
    print(*sorted(components[i]))
