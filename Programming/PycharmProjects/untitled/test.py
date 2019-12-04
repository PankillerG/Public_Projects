N = int(input())
data = dict()

for i in range(N):
    string_temp = input()
    key_ans = string_temp[:string_temp.find(' ')]
    key = list(string_temp[string_temp.find(' ')+3:].split(', '))
    for j in key:
        if j not in data:
            list_temp = list()
            list_temp.append(key_ans)
            data.update({j: list_temp})
        else:
            list_temp = data[j]
            list_temp.append(key_ans)
            data.update({j: list_temp})

for el in sorted(data):
    data_temp = sorted(data[el])
    print(el, '-', end=" ")
    print(*data_temp, sep=', ')


'''
2
cut - вырезать, удалить
delete - стереть, удалить
'''