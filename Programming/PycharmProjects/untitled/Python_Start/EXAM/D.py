n = int(input())
langs = dict()
lang = dict()
for i in range(n):
    key = input()
    value = input()
    langs[key] = set(value)
for i in range(int(input())):
    l = input()
    lList = list(l)
    lang[l] = ''
    for key in langs:
        flag = True
        for j in range(len(lList)):
            if flag and lList[j] in langs[key]:
                key = str(' ' + key)
                lang[l] += key
                flag = False
for key in lang:
    lastList = lang[key].split()
    lastList.sort()
    print(*lastList)
