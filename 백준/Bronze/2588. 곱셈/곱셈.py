a=input()
b=input()
res=[]

for i in range(3):
    buf=0
    for j in range(2,-1,-1):
        if j==2:
            buf+=int(a[j])*int(b[i])
        elif j==1:
            buf+=int(a[j])*int(b[i])*10
        elif j==0:
            buf+=int(a[j])*int(b[i])*100
    res.append(buf)


for i in range(2,-1,-1):
    print(res[i])
print(int(a)*int(b))
