num = int(input())
nums = [0 for i in range(9)]
while num != 0:
    nums[num - 1] += 1
    num = int(input())
for i in range(9):
    print(nums[i], end=' ')
