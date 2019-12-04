count = int(input())
persons = []
for i in range(count):
    persons.append(input())
persons.sort(reverse=True, key=lambda x: int(x[x.find(' ') + 1:]))
for i in range(count):
    print(persons[i][:persons[i].find(' ')])
