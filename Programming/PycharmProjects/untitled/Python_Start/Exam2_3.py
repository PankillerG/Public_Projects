n = int(input())
sum_ = 0
for i in range(1, n):
    sum_ += i * (i + 1)
    print(i, '*', (i + 1), sep='', end='')
    if i != n - 1:
        print('+', sep='', end='')
print('=', sum_, sep='')