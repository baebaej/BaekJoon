t=int(input())
res=[0]*t
for k in range(t):
    r,s=input().split()
    r=int(r)

    p=[]
    for i in range(len(s)):
        for j in range(r):
            p.append(s[i])

    p=''.join(p)
    res[k]=p

for i in range(t):
    print(res[i])
