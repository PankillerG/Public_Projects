wordList = [1, 2, 5, 5, 3, 4, 5, 5, 5, 5]
wordList2 =[]
for i in range(1, len(wordList) - 1):
    if wordList[i - 1] != wordList[i]:
        wordList2.append(wordList[i - 1])
if wordList[len(wordList) - 1] == wordList[len(wordList) - 2]:
    wordList2.append(wordList[-1])
print(wordList2)
