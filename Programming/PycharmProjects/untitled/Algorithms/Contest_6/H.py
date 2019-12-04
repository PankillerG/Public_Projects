n = int(input())
graph = list()
visited = [0] * n
before = [0] * n
distance = [-1] * n
willuse = list()
all = list()
for i in range(n):
    graph.append([])
for i in range(n):
    local = list(map(int, input().split()))
    for j in range(len(local)):
        graph[i].append(local[j])
first, last = map(int, input().split())
first, last = first - 1, last - 1
distance[first], visited[first] = 0, 1
willuse.append(first)
while len(willuse) != 0:
    for vertex in range(n):
        temp = willuse[0]
        if graph[temp][vertex] != 0 and \
                visited[vertex] == 0:
            visited[vertex] = 1
            distance[vertex] = distance[temp] + 1
            willuse.append(vertex)
            before[vertex] = temp
    temp = willuse[0]
    willuse.remove(temp)
dist = distance[last]
print(dist)
if dist > 0:
    while first != last:
        all.append(last + 1)
        last = before[last]
    all.append(last + 1)
    all.reverse()
    print(*all)
