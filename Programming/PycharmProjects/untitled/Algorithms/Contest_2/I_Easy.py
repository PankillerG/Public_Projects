n = int(input())
list1 = list(map(int, input().split()))
m = int(input())
list2 = list(map(int, input().split()))
i, j = 0, 0
minimal = abs(list1[i] - list2[j])
cloth1, cloth2 = list1[i], list2[j]
while i < len(list1) and j < len(list2):
    if abs(list1[i] - list2[j]) < minimal:
        minimal = abs(list1[i] - list2[j])
        cloth1 = list1[i]
        cloth2 = list2[j]
    if list1[i] < list2[j]:
        i += 1
    else:
        j += 1
print(cloth1, cloth2)
