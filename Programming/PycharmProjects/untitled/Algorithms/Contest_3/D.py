dictL = dict()
file = open('input.txt', 'r')
string = str(file.read())
string = string.replace('\n', '')
string = string.replace(' ', '')
for char in string:
    if char in dictL:
        dictL[char] += 1
    else:
        dictL[char] = 1
dictL = dict(sorted(dictL.items()))
maximum = max(dictL.values())
for i in range(maximum):
    for key, value in dictL.items():
        if value > 0 and value == maximum:
            print('#', end='')
            dictL[key] -= 1
        elif value > 0:
            print(' ', end='')
    print()
    maximum -= 1
for key in dictL.keys():
    print(key, end='')
