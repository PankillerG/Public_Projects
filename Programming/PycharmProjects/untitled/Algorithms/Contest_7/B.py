def time(vertex):
    global willuse
    for v in range(n):
        for t in range(len(graph[vertex][v])):
            if graph[vertex][v] != []:
                if graph[vertex][v][t][1] < period[v]:
                    period[v] = graph[vertex][v][t][1]
                    willuse.append(v)
    while len(willuse) != 0:
        local = willuse[0]
        willuse.remove(local)
        for v in range(n):
            for t in range(len(graph[local][v])):
                if graph[local][v] != []:
                    if period[local] <= graph[local][v][t][0] and \
                            period[v] > graph[local][v][t][1]:
                        period[v] = graph[local][v][t][1]
                        willuse.append(v)
    if period[f - 1] != number:
        print(period[f - 1])
    else:
        print(-1)


n = int(input())
s, f = map(int, input().split())
graph = []
for i in range(n):
    graph.append([])
    for j in range(n):
        graph[i].append([])
number = 10 ** 100
period = [number] * n
period[s - 1] = 0
willuse = list()
for i in range(int(input())):
    temp = list()
    local = list(map(int, input().split()))
    temp.append(local[1])
    temp.append(local[3])
    graph[local[0] - 1][local[2] - 1].append(temp)
time(s - 1)
