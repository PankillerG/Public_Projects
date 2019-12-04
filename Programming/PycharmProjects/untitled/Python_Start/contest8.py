file1 = open('input.txt', 'r', encoding='utf-8')
partiesFlag = False
votesFlag = False
parties = []
partiesCount = []
count = 0
for line in file1:
    if line.strip() == 'PARTIES:':
        partiesFlag = True
        continue
    if line.strip() == 'VOTES:':
        partiesFlag = False
        votesFlag = True
        continue
    if partiesFlag:
        parties.append(line.strip('\n'))
        partiesCount.append(0)
    if votesFlag:
        count += 1
        for i in range(len(parties)):
            if parties[i] == line.strip('\n'):
                partiesCount[i] += 1
                break
for i in range(len(parties)):
    parties[i] = parties[i] + ' ' + str(partiesCount[i])
parties.sort()
parties.sort(key=lambda x: int(x[x.rfind(' ') + 1:]), reverse=True)
for i in range(len(parties)):
    print(parties[i][:parties[i].rfind(' ')])
