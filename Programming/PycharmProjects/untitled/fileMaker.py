for i in range(1, 16, 1):
    name = "000" + str(i)
    name = name[-3:]
    f = open(name + '.dat', 'w')
    f = open(name + '.ans', 'w')