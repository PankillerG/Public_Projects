file = open('input.txt', 'r')
words = dict()
wordsList = []
for line in file:
    string = line.split()
    for i in range(len(string)):
        if string[i] in words:
            words[string[i]] += 1
        else:
            words[string[i]] = 1
for key in words:
    wordsList.append([words[key], key])
wordsList = sorted(wordsList, key=lambda x: x[1])
wordsList = sorted(wordsList, key=lambda x: x[0], reverse=True)
for i in range(len(wordsList)):
    print(wordsList[i][1])
