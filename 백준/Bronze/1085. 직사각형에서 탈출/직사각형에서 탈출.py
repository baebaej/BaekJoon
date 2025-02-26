import math as m

x,y,w,h=map(int, input().split())
x=int(x)
y=int(y)
w=int(w)
h=int(h)

tmp=[]
tmp.append(x)
tmp.append(y)
tmp.append(w-x)
tmp.append(h-y)
tmp.sort()

res=tmp[0]
print(res)
