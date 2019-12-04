import sys
sys.setrecursionlimit(100000)


def dfs(number, colour):
    global flag
    local[number] = colour
    visited[number] = 1
    for vertex in graph[number]:
        if visited[vertex] == 0:
            dfs(vertex, (colour + 1) % 2)
        if visited[vertex] == 1 and local[vertex] == colour:
            flag = True


n, m = map(int, input().split())
graph = []
visited = [0] * n
local = [0] * n
for i in range(n):
    graph.append([])
for i in range(m):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
flag = False
for vertex in range(n):
    if visited[vertex] == 0:
        dfs(vertex, 0)
if flag:
    print('NO')
else:
    print('YES')
