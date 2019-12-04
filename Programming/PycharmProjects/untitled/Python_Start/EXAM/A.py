from math import factorial
n = int(input())
sum_ = 0
for i in range(1, n + 1):
    sum_ += factorial(i)
print(sum_)
