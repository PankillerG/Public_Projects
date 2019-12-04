word = input()
word1 = word[0]
word = word[1:]
for char in word:
    if char not in set('aehiouwy'):
        if char in set('bfpv'):
            word1 += '1'
        if char in set('cgjkqsxz'):
            word1 += '2'
        if char in set('dt'):
            word1 += '3'
        if char in set('l'):
            word1 += '4'
        if char in set('mn'):
            word1 += '5'
        if char in set('r'):
            word1 += '6'
word = word1[0]
word1 += '_'
for i in range(1, len(word1) - 1):
    if word1[i] != word1[i + 1]:
        word += word1[i]
if len(word) >= 4:
    word = word[0:4]
else:
    word += '0' * (4 - len(word))
print(word)
