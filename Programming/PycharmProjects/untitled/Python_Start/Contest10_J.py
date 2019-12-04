file = open('input.txt', 'r')
partys = dict()
count = 0
countAll = 0
partysPlace = dict()
countLastPlaces = 0
p2 = dict()
for line in file:
    line = line.strip('\n')
    party = line[:line.rfind(' ')]
    count = int(line[line.rfind(' ') + 1:])
    countAll += count
    if party in partys:
        partys[party] += count
    else:
        partys[party] = count
index = countAll / 450
for key in partys:
    partysPlace[key] = partys[key] // index
    countLastPlaces += partys[key] // index
p2 = sorted(partys.items(), key=lambda x: x[1] % index, reverse=True)
for key, value in p2:
    if countLastPlaces < 450:
        partysPlace[key] += 1
        countLastPlaces += 1
for key in partysPlace:
    print(key, int(partysPlace[key]))
