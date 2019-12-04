n = int(input())
sumCard = 0
for i in range(1, n + 1):
    sumCard += i
for i in range(n - 1):
    sumCard -= int(input())
print(sumCard)
