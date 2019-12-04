def partition(last, mid):
    ind = 0
    i = 0
    while i <= last:
        if list1[i] < mid:
            ind += 1
        else:
            list1[i], list1[ind] = list1[ind], list1[i]
        i += 1
    return ind - 1

n = int(input())
list1 = list(map(int, input().split()))
pr = int(input())
less = partition(n - 1, pr) + 1
print(less)
print(n - less)
