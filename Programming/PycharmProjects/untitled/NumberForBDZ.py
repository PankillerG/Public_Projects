file = open('number_pi', 'r')
nGroup = 187
nStud = 7
print("Задайте диапозон значений номеров в ввиде: (двух числе a, b: [a, b])")
first, second = map(int, input().split())
for number_now in range(first, second + 1):
    number = (number_now - 1) * 300 + (nGroup - 183) * 35 + nStud
    print("В задании:", number_now, "ваш номер числа pi:", number)
    print("совпадает с людьми:")
    for group in range(183, 189 + 1):
        for person in range(1, 30 + 1):
            number_temp = (number_now - 1) * 300 + (group - 183) * 35 + person
            if number_temp == number:
                print("группа: ", group, ", человек номер: ", person, sep="")
    print()

