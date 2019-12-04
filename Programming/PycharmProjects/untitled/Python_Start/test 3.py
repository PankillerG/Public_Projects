a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
f = int(input())
if a == 0:
    if d != 0:
        y = e / b
        x = (f - d * y) / c
    else:
        x = f / c
        y = e / b
elif c == 0:
    if b != 0:
        y = f / d
        x = (e - b * y) / a
    else:
        y = f / d
        x = e / a
else:
    y = (a * f - c * e) / (d * a - b * c)
    x = (e - b * y) / a
print(x, y)
