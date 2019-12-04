line = input()
part1 = line[:line.find('h') + 1]
part2 = line[line.rfind('h') - 1:line.find('h'):-1]
part3 = line[line.rfind('h'):]
line = part1 + part2 + part3
print(line)
