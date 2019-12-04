file = open('input.txt', 'r')
presidents = dict()
count = 0
index1 = 0
flag = 1
for line in file:
    count += 1
    line = line.strip('\n')
    if line in presidents:
        presidents[line] += 1
        if presidents[line] > index1:
            index1 = presidents[line]
    else:
        presidents[line] = 1
        if presidents[line] > index1:
            index1 = presidents[line]
presidents = sorted(presidents.items(), key=lambda x: x[1], reverse=True)
presidents = dict(presidents)
if index1 > count / 2:
    for key in presidents:
        print(key)
        break
else:
    for key in presidents:
        if flag <= 2:
            print(key)
            flag += 1
        else:
            break
