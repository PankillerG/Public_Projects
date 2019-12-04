file = open('input.txt', 'r')
firstFlag = True
for line in file:
    if firstFlag:
        first = line.split()
print(first)
