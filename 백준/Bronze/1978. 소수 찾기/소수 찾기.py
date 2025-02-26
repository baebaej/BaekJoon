num=int(input())
a = [int(x) for x in input().strip().split()]

cnt=0
prime_cnt=0
for i in range(num):
    for j in range(2,a[i]):
        if(a[i]==1):
            break
        if(a[i]%j==0):
            cnt+=1
            break
    if(a[i]!=1 and cnt==0):
        prime_cnt+=1
    cnt=0
    
print(prime_cnt)
