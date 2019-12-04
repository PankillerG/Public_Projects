file = open('input.txt', 'r')
first = True
firstline = ''
for line in file:
    if first:
        firstline = line
        firstline = firstline.strip('\n')
        first = False
        if firstline != '':
            c = int(line[line.find(' ') + 1:])
        continue
    if firstline == '':
        print(line.strip('\n'))
    if firstline != '':
        for i in range(c - 1):
            line = line[line.find('\t') + 1:]
        if line.count('\t') != 0:
            print(line[:line.find('\t')])
        else:
            print(line.strip('\n'))
