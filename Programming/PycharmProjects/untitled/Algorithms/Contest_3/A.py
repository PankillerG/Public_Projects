n = int(input())
workBut = list(map(int, input().split()))
k = int(input())
push = list(map(int, input().split()))
for i in range(len(push)):
    workBut[push[i] - 1] -= 1
for i in range(len(workBut)):
    if workBut[i] >= 0:
        print('no')
    else:
        print('yes')

