res=[]

while True:
    try:
        a,b=input().split()
        a=int(a)
        b=int(b)
        res.append(a+b)
    except:
        break

for i in range(len(res)):
    print(res[i])
