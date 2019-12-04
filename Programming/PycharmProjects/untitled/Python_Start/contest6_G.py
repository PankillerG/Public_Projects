a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
sumX = 0
for i in range(0, 1001):
    if (i - e) != 0 and (a * i ** 3 + b * i ** 2 + c * i + d) / (i - e) == 0:
        sumX += 1
print(sumX)
