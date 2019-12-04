import sys
sys.setrecursionlimit(1000000)


def dfs(number):
    global flag
    visited[number] = 1
    if local[1] < flag:
        local[1] = flag
        local[0] = number
    for vertex in graph[number]:
        if visited[vertex] == 0:
            flag = flag + 1
            dfs(vertex)
            flag = flag - 1


n = int(input())
graph = []
visited = [0] * n
local = [1, 0]
flag = 0
for i in range(n):
    graph.append([])
for i in range(n - 1):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
dfs(1)
local[1] = 0
visited = [0] * n
dfs(local[0])
print(local[1])
