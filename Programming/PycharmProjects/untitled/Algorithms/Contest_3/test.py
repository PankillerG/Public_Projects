w, s = map(int, input().split())
stringW = input()
stringS = input()
if len(stringW) <= len(stringS):
    dict1 = dict()
    dict2 = dict()
    list1 = list()
    for char in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ':
        dict1[char] = 0
        dict2[char] = 0
    for char in stringW:
        dict1[char] += 1
    i = 0
    lenW = len(stringW)
    lenS = len(stringS)
    k = 1
    count = 0
    for char in stringS[i: i + lenW]:
        dict2[char] += 1
    for char in dict1:
        if dict1[char] > 0 and dict1[char] == dict2[char]:
            k += 1
    i = 0
    while i + lenW < lenS:
        print(k)
        dict2[stringS[i]] -= 1
        dict2[stringS[i + lenW]] += 1
        if dict1[stringS[i]] > 0 and \
                dict1[stringS[i]] == dict2[stringS[i]]:
            k -= 1
        elif dict1[stringS[i]] == dict2[stringS[i]] + 1:
            k += 1
        if dict1[stringS[i + lenW]] > 0 and \
                dict1[stringS[i + lenW]] == dict2[stringS[i + lenW]]:
            k -= 1
        elif dict1[stringS[i + lenW]] == dict2[stringS[i + lenW]] + 1:
            k -= 1
        if k == 0:
            count += 1
        i += 1
    print(k)
else:
    print(0)
