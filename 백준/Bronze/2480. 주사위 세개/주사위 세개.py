a,b,c=map(int,input().split())
num=[]
num.append(a)
num.append(b)
num.append(c)
cnt=[]

for i in range(1,7):
    buf=num.count(i)
    cnt.append(buf)
    if buf==3:
        res=10000+i*1000
        break
    elif buf==2:
        res=1000+i*100
        break
    elif buf==1:
        res=i*100
print(res)
