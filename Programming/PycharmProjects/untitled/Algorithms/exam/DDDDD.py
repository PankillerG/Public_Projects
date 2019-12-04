'''def mySqrt(a, n):
    l = 0
    r = 1000 * 1000
    eps = 0.00000001
    while (r - l > eps):
        m = (r + l) / 2
        if m ** n <= a:
            l = m
        else:
            r = m
    return l


a = float(input())
n = int(input())
print(mySqrt(a, n))'''


a = float(input())
n = int(input())
local = 0.00000000001
first, last = 0, 1000000
while local < last - first:
    temp = last + first
    temp /= 2
    if a < temp ** n:
        last = temp
    else:
        first = temp
print(first)
