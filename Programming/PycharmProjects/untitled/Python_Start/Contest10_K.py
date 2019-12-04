inFile = open('input.txt', 'r')
myDict = dict()
for line in inFile:
    name, product, howMany = line.split()
    if name not in myDict:
        myDict[name] = {product: howMany}
    else:
        if product not in myDict[name].keys():
            myDict[name].update({product: howMany})
        else:
            myDict[name][product] = int(myDict[name][product]) + int(howMany)
for i in sorted(myDict.keys()):
    print(i + ':')
    for j in sorted(myDict[i].keys()):
        print(j, myDict[i][j])