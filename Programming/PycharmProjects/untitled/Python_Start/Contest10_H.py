file = open('input.txt', 'r')
buys = dict()
for line in file:
    person, thing, count = line.split()
    count = int(count)
    if person not in buys:
        buys[person] = {thing: count}
    elif thing not in buys[person]:
        buys[person][thing] = count
    else:
        buys[person][thing] += count
for key in sorted(buys.keys()):
    print(key + ':', sep='')
    for key1 in sorted(buys[key].keys()):
        print(key1, buys[key][key1])
