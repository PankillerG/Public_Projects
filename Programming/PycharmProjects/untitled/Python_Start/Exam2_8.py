sizes = sorted(list((map(int, input().split()))), reverse=True)
boots = sorted(list(map(int, input().split())), reverse=True)
count = 0
for i in range(len(boots)):
    for j in range(len(sizes)):
        if boots[i] <= sizes[j] and boots[i] > 0:
            count += 1
            boots[i] = -1
            sizes[j] = -2
print(count)
