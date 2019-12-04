def length(vertex):
    global willuse
    for v in range(n):
        if graph[vertex][v] != 0 and graph[vertex][v] != -1:
            distance[v] = graph[vertex][v]
            willuse.append(v)
    while len(willuse) != 0:
        local = willuse[0]
        willuse.remove(local)
        for v in range(n):
            if graph[local][v] != -1 and \
                    graph[local][v] < distance[v] - distance[local]:
                distance[v] = graph[local][v] + distance[local]
                willuse.append(v)
    if distance[f - 1] != number:
        print(distance[f - 1])
    else:
        print(-1)


n, s, f = map(int, input().split())
graph = []
number = 10 ** 100
distance = [number] * n
distance[s - 1] = 0
willuse = list()
for i in range(n):
    local = list(map(int, input().split()))
    graph.append(local)
length(s - 1)
