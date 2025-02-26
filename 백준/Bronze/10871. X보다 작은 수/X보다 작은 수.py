n,x=input().split()
n=int(n)
x=int(x)
a=[int(x) for x in input().split()]

for i in range(n):
    if a[i]<x:
        print(a[i],end=' ')
