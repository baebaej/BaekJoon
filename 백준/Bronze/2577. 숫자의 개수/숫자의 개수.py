a=int(input())
b=int(input())
c=int(input())

multi=a*b*c
multi=str(multi)
cnt=0
for i in range(10):
    for j in range(len(multi)):
        if str(i)==multi[j]:
            cnt+=1
    print(cnt)
    cnt=0
