def insertionSort(last):
    for i in range(last):
        key = theList[i]
        j = i - 1
        count = 0
        while j >= 0 and theList[j] > key:
            theList[j + 1] = theList[j]
            j -= 1
            count = 1
            theList[j + 1] = key
        if count == 1:
            print(*theList)


num = int(input())
theList = list(map(int, input().split()))
insertionSort(num)
