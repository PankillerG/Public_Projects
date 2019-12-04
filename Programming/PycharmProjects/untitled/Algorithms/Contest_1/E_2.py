num = int(input())
list1 = list(map(int, input().split()))
count = 0
i = 0
while count < num * 3:
    if i < num - 1 and list1[i + 1] - list1[i] > 1:
        list1[i], list1[i + 1] = list1[i + 1], list1[i]
        print(list1[i + 1], list1[i])
        count = 0
    else:
        count += 1
    if i == len(list1) - 1 > 1:
        if list1[0] - list1[i] > 1:
            list1[i], list1[0] = list1[0], list1[i]
            print(list1[0], list1[i])
            count = 0
        else:
            count += 1
        i = -1
    i += 1
else:
    print(0)
