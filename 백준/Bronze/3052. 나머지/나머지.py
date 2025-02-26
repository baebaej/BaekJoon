mem=[]
for i in range(10):
    a=int(input())
    mem.append(a%42)
cnt=0
for i in range(10):
    main=mem[i]
    j=i+1
    same=0
    while j<10:
        if main==mem[j]:
            same=1
            break
        j+=1
    if same!=1:
        cnt+=1

print(cnt)
