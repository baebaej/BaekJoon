a,b=input().split()
A=[]
B=[]
i=len(a)-1
while i>=0:
    A.append(a[i])
    i-=1
i=len(b)-1
while i>=0:
    B.append(b[i])
    i-=1
A=int(''.join(A))
B=int(''.join(B))
if A>B:
    print(A)
else:
    print(B)
