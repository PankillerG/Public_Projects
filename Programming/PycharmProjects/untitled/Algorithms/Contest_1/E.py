def finder(num):
    for ii in range(len(list1)):
        if list1[ii] == num:
            return ii


def switcher(num):
    index = finder(num)
    for i in range(len(list1)):
        if index + 1 <= len(list1) - 1 and \
                list1[index + 1] - list1[index] > 1:
            list1[index], list1[index + 1] = list1[index + 1], list1[index]
        if index == len(list1) - 1:
            if list1[0] - list1[index] > 1:
                list1[index], list1[0] = list1[0], list1[index]


def switcherAll(num):
    while num != 0:
        switcher(num)
        num -= 1


num = int(input())
list1 = list(map(int, input().split()))
for i in range(len(list1)):
    switcherAll(i)
print(list1)
