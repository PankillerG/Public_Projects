n, m = map(int, input().split())
graph = []
elements = list()
trees = {}
all = 0
for i in range(m):
    el = list(map(int, input().split()))
    graph.append((el[3] * (-el[2]), el[0], el[1]))
for j in range(n):
    temp = j + 1
    trees[j] = temp
graph.sort(key=lambda element: element[0])
for elem in graph:
    v2 = elem[2]
    v1 = elem[1]
    if trees[v2] != trees[v1]:
        all = all - elem[0]
        b = trees[v2]
        a = trees[v1]
        for i in range(n):
            if trees[i] == b:
                trees[i] = a
print(all)
