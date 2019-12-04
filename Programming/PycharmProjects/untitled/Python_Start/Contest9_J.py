n, k = map(int, input().split())
counter = set()
for i in range(k):
    a, b = map(int, input().split())
    while a <= n:
        if a % 7 != 0 and (a + 1) % 7 != 0:
            counter.add(a)
        a += b
print(len(counter))
