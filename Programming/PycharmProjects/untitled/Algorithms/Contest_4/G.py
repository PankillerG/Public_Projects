n = int(input())
listall = list()
for i in range(n):
    listall.append(int(input()))
setall = {0, 1}
setall2 = set()
for i in range(n):
    if listall[i] in setall:
        print('Yes')
    elif listall[i] > max(setall):
        setall2 = setall.copy()
        setall2.discard(max(setall2))
        first = max(setall2)
        second = max(setall)
        while second < listall[i]:
            local = second
            second += first
            first = local
            setall.add(second)
        if second == listall[i]:
            print('Yes')
        else:
            print('No')
    else:
        print('No')
