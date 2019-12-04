num = int(input())
theList = list(map(int, input().split()))
count = 0
for i in range(num - 1):
    for j in range(i, num):
        if theList[i] > theList[j]:
            count += 1
print(count)
