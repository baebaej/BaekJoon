N=input()

length=len(N)
pd1=1
pd2=1
isok=False
for i in range(1, length):
    for j in range(i):
        pd1*=int(N[j])
    for j in range(i,length):
        pd2*=int(N[j])
    #print(pd1, pd2)
    if pd1==pd2:
        isok=True
        break
    pd1=1
    pd2=1

if isok==True:
    print("YES")
else:
    print("NO")
