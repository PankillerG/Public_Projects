n = int(input())
localLanguages = set()
languagesAll = set()
language = set()
for i in range(n):
    localLanguages.clear()
    for j in range(int(input())):
        localLanguages.add(input())
    if i != 0:
        language = language & localLanguages
    else:
        language = localLanguages
    languagesAll |= localLanguages
if len(language) == 0:
    print(0)
else:
    print(len(language))
    for elem in language:
        print(elem)
print(len(languagesAll))
for elem in languagesAll:
    print(elem)
