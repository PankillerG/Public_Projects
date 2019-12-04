n, k = map(int, input().split())
dates = set()
weekends = set(range(6, n + 1, 7))
weekends2 = set(range(7, n + 1, 7))
weekends |= weekends2
for i in range(k):
    a, b = map(int, input().split())
    dates |= set(range(a, n + 1, b))
dates -= weekends
print(len(dates))
