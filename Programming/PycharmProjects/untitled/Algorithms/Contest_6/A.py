import sys
sys.setrecursionlimit(100000)


def dfs(number):
    visited[number] = 1
    for vertex in graph[number]:
        if visited[vertex] == 0:
            dfs(vertex)


n, m = map(int, input().split())
graph = []
visited = [0] * n
for i in range(n):
    graph.append([])
for i in range(m):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
dfs(0)
print(visited.count(1))
for vertex in range(len(visited)):
    if visited[vertex] == 1:
        print(vertex + 1, end=' ')
