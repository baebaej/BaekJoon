t=int(input())
i=0
a=[0]*t
while i<t:
    n,m=input().split()
    n=int(n)
    m=int(m)
    res=1
    division=n
    j=0
    while j<n:
        res=res*m
        res=res/division
        m-=1
        j+=1
        division-=1
    res=round(res)
    a[i]=res
    i+=1

for i in range(t):
    print(a[i])
