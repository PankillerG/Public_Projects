from math import fabs
n = int(input())
vilages = list(map(int, input().split()))
m = int(input())
bunkers = list(map(int, input().split()))
for i in range(len(bunkers)):
    bunkers[i] = str(bunkers[i]) + ' ' + str(i)
bunkers.sort(key=lambda x: int(x[:x.find(' ')]))
for i in range(len(vilages)):
    mind = fabs(vilages[i] - int(bunkers[0][:bunkers[0].find(' ')]))
    index = int(bunkers[0][bunkers[0].find(' ') + 1:]) + 1
    for j in range(len(bunkers)):
        if fabs(vilages[i] - int(bunkers[j][:bunkers[j].find(' ')])) < mind:
            mind = fabs(vilages[i] - int(bunkers[j][:bunkers[j].find(' ')]))
            index = int(bunkers[j][bunkers[j].find(' ') + 1:]) + 1
        if fabs(vilages[i] - int(bunkers[j][:bunkers[j].find(' ')])) > mind:
            break
    print(index, end=' ')
