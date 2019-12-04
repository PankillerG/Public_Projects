n = int(input())
print('+___ ' * n, end='')
print()
for i in range(1, n + 1):
    print('|', i, ' / ', sep='', end='')
print()
print('|__\\ ' * n, end='')
print()
print('|    ' * n, end='')
