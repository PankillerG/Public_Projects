m = int(input())
maximum = 0
list_ = list()
for i in range(m):
    n = int(input())
    local = list()
    for j in range(n):
        local.append(input())
    if len(local) > maximum:
        maximum = len(local)
    list_.append(local)
totallocal = list()
for i in range(maximum):
    totallocal.append(list())
for i in range(len(list_)):
    for j in range(maximum):
        if j in range(len(list_[i])):
            totallocal[j].append(list_[i][j])
            totallocal[j].append("\t")
        else:
            totallocal[j].append('\t')
for i in range(len(totallocal)):
    for j in range(len(totallocal[i])):
        if j != len(totallocal[i]) - 1:
            print(totallocal[i][j], end='')
        else:
            print(totallocal[i][j], end='\n')
