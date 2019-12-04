n, m = map(int, input().split())
s1 = input()
s2 = input()
dictT = dict()
count = 0
k = 0
string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
list1 = [0] * 52
list2 = [0] * 52
for i in range(52):
    dictT[string[i]] = i
for i in s1:
    list1[dictT[i]] += 1
for i in range(len(s1)):
    list2[dictT[s2[i]]] += 1
for i in range(52):
    if list1[i] != list2[i]:
        k += 1
if k == 0:
    count += 1
for i in range(len(s1), len(s2)):
    if list1[dictT[s2[i]]] == list2[dictT[s2[i]]]:
        k += 1
    list2[dictT[s2[i]]] += 1
    if list1[dictT[s2[i]]] == list2[dictT[s2[i]]]:
        k -= 1
    if list1[dictT[s2[i - len(s1)]]] == list2[dictT[s2[i - len(s1)]]]:
        k += 1
    list2[dictT[s2[i - len(s1)]]] -= 1
    if list1[dictT[s2[i - len(s1)]]] == list2[dictT[s2[i - len(s1)]]]:
        k -= 1
    if k == 0:
        count += 1
print(count)
