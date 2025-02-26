num=int(input())
numbers=[int(x) for x in input().strip().split()]


max_num=numbers[0]
min_num=numbers[0]
for i in range(num):
    if numbers[i]>max_num:
        max_num=numbers[i]
    if numbers[i]<min_num:
        min_num=numbers[i]

print(min_num, max_num)
