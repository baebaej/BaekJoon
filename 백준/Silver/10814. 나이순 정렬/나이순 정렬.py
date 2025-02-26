n=int(input())

array=[[] for row in range(n)]
for i in range(n):
    a,b=input().split()
    a=int(a)
    array[i].append(a)
    array[i].append(i+1)
    array[i].append(b)

#print(array)

array.sort()
#print(array)

for i in range(n):
    print(array[i][0], array[i][2])
