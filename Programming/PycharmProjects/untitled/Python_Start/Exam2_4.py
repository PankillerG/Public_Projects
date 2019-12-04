n = int(input())
l = list(map(int, input().split()))
count = 0
for i in range(n):
    for j in range(i, n):
        for k in range(j, n):
            if l[i] < l[j] + l[k] and l[j] < l[i] + l[k] \
                    and l[k] < l[i] + l[j]:
                if i != j and i != k and k != j:
                    count += 1
print(count)
