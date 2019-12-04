dict1 = dict()
n = int(input())
string = input()
mid = 'ZZ'
for i in range(len(string)):
    if string[i] in dict1:
        dict1[string[i]] += 1
    else:
        dict1[string[i]] = 1
dict1 = dict(sorted(dict1.items()))
for key in dict1:
    if dict1[key] % 2 == 1 and key < str(mid):
        mid = key
        dict1[key] -= 1
    elif dict1[key] % 2 == 1:
        dict1[key] -= 1
    if dict1[key] % 2 == 0:
        print(key * (dict1[key] // 2), end='')
        dict1[key] -= dict1[key] // 2
    else:
        dict1[key] = -1
if mid != 'ZZ':
    print(mid, end='')
dict1 = dict(sorted(dict1.items(), reverse=True))
for key in dict1:
    if dict1[key] > 0:
        print(key * dict1[key], end='')
