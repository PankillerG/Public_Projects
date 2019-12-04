n = int(input())
list1 = list()
for i in range(n):
    list1.append(input())
print('Initial array:')
for i in range(n):
    if i < n - 1:
        print(list1[i], end=', ')
    else:
        print(list1[i])
maximum = len(list1[0])
list0_9 = [[] for i in range(10)]
for i in range(maximum - 1, -1, -1):
    print('**********')
    print('Phase', maximum - i)
    for j in range(len(list1)):
        list0_9[int(list1[j][i:i + 1])].append(list1[j])

    for j in range(len(list0_9)):
        if len(list0_9[j]) == 0:
            print('Bucket ', j, ': empty', sep='')
        else:
            print('Bucket ', j, ': ', end='', sep='')
            for c in range(len(list0_9[j])):
                if c < len(list0_9[j]) - 1:
                    print(list0_9[j][c], end=', ')
                else:
                    print(list0_9[j][c])

    list1 = []
    for j in range(len(list0_9)):
        list1 += list0_9[j]
    list0_9 = [[] for i in range(10)]
print('**********')
print('Sorted array:')
for i in range(len(list1)):
    if i < len(list1) - 1:
        print(list1[i], end=', ')
    else:
        print(list1[i])
