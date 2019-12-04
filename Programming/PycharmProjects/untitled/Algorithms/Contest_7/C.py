def dj(vertex, some):
    global willuse
    period = [number] * n
    for v in range(n):
        if vertex != v and len(graph[vertex][v]) != 0 and \
                some <= weight[vertex][v][0]:
            period[v] = graph[vertex][v][0]
            willuse.append(v)
    while len(willuse) != 0:
        local = willuse[0]
        willuse.remove(local)
        for v in range(n):
            if (local != v and
                len(graph[local][v]) != 0 and
                    some <= weight[local][v][0] and
                    graph[local][v][0] <= 1440 - period[local] and
                    graph[local][v][0] < period[v] - period[local]):
                period[v] = graph[local][v][0] + period[local]
                willuse.append(v)
    if 1440 < period[n - 1]:
        return 0
    else:
        return 1


def notBinSearch():
    first, last = 0, len(temp2) - 1
    mid = last + first
    mid //= 2
    while last >= first:
        mid = last + first
        mid //= 2
        if dj(0, temp2[mid]) == 0:
            last = mid - 1
        else:
            first = mid + 1
    if dj(0, temp2[last]) == 0:
        return temp2[first]
    else:
        return temp2[last]


n, m = map(int, input().split())
graph = list()
weight = list()
willuse = list()
all = 0
local = list()
temp = list()
temp2 = list()
period = list()
if m == 0:
    print(10 ** 7)
else:
    for i in range(n):
        graph.append([])
        weight.append([])
        for j in range(n):
            graph[i].append([])
            weight[i].append([])
    number = 10 ** 100
    for i in range(m):
        local = list(map(int, input().split()))
        if 1440 >= local[2]:
            temp.append(local[3])
        graph[local[0] - 1][local[1] - 1].append(local[2])
        weight[local[0] - 1][local[1] - 1].append(local[3])
        graph[local[1] - 1][local[0] - 1].append(local[2])
        weight[local[1] - 1][local[0] - 1].append(local[3])
    temp2 = temp.copy()
    temp2 = sorted(temp2)
    all = notBinSearch()
    if dj(0, all) == 1 and 3000000 < all:
        answer = all - 3000000
        answer //= 100
        print(answer)
    else:
        print(0)
