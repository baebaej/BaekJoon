n,k=input().split()
n=int(n)
k=int(k)

res=1
for i in range(n,n-k,-1):
    res*=i
for j in range(k,0,-1):
    res/=j
print(round(res))
