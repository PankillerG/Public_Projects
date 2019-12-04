w, s = map(int, input().split())
stringW = input()
stringS = input()
lenW = len(stringW)
lenS = len(stringS)
dictW = dict()
dictS = dict()
count = 0
for char in 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ':
    dictW[char] = 0
    dictS[char] = 0

for char in stringW:
    dictW[char] += 1
for char in stringS[0: lenW]:
    dictS[char] += 1

k = 0
for key in dictW:
    if dictW[key] > 0 and dictW[key] == dictS[key]:
        k += dictS[key]
if k == lenW:
    count += 1

i = 0
while i + lenW <= lenS:
    print('i', i)
    if dictS[stringS[i - 1]] != dictS[stringS[i + lenW]]:
        dictS[stringS[i - 1]] -= 1
        dictS[stringS[i + lenW]] += 1
        if dictS[stringS[i - 1]] > 0 and \
            dictS[stringS[i - 1]] == dictW[stringS[i - 1]]:
            k += 1
        elif dictS[stringS[i - 1]] + 1 == dictW[stringS[i - 1]]:
            k -= 1
        if dictS[stringS[i + lenW]] == dictW[stringS[i + lenW]]:
            k += 1
    if k == lenW:
        count += 1
    i += 1

print(count)
