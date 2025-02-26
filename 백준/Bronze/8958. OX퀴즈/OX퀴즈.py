n=int(input())
res=[]
for i in range(n):
    s=0
    buf=0
    case=input()
    for j in range(len(case)):
        if s==0 and case[j]=='O':
            s+=1
            buf+=1
        elif s>0 and case[j]=='O':
            s+=1
            buf+=s
        elif case[j]=='X':
            s=0
        #print(buf)
    res.append(buf)
    s=0
    buf=0

for i in range(len(res)):
    print(res[i])
