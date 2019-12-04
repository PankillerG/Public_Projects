def maximumInLast(first, last):
    maximum = theList[0]
    index = 0
    for i in range(last):
        if theList[i] > maximum:
            maximum = theList[i]
            index = i
    if theList[last] < theList[index]:
        theList[index], theList[last] = theList[last], theList[index]


first = 0
last = int(input())
if last > 0:
    theList = list(input().split())
    maximumInLast(first, last - 1)
    print(*theList)
