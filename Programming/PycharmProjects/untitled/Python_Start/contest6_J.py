n = int(input())
fact = 1
sumFact = 0
for i in range(1, n + 1):
    fact *= i
    sumFact += fact
print(sumFact)
