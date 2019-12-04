n = int(input())
numbersYes = set()
numbersNo = set()
line1 = input()
firstTime = True
while line1 != 'HELP':
    line2 = input()
    if line2 == 'YES':
        if firstTime:
            numbersYes |= set(map(int, line1.split()))
            firstTime = False
        else:
            numbersYes &= set(map(int, line1.split()))
    if line2 == 'NO':
        numbersNo |= set(map(int, line1.split()))
    line1 = input()
if len(numbersYes) == 0:
    all = set()
    for i in range(1, n + 1):
        all.add(i)
    print(*sorted(all - numbersNo))
else:
    print(*sorted(numbersYes - numbersNo))
