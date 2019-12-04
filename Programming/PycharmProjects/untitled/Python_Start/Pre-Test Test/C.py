things = []
carsNum = {}
count = 0
for i in range(int(input())):
    things.append(input())
for i in range(int(input())):
    key = input()
    carsNum[key] = 0
    for thing in things:
        for ch in thing:
            if ch in set(key):
                count += 1
        if count == len(thing):
            carsNum[key] += 1
        count = 0
if len(carsNum) > 0:
    maximum = max(carsNum.values())
for key in carsNum:
    if carsNum[key] == maximum:
        print(key)

