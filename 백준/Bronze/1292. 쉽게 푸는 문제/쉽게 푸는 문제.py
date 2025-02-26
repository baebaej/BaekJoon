a,b=input().split()
a=int(a)
b=int(b)
sum=0
i=1
mem=[1]
while sum<1000:
    sum+=i
    i+=1
    for j in range(i):
        mem.append(i)

i=1
sum_num=0
while i<=b:
    if i>=a and i<=b:
        sum_num+=mem[i-1]
    i+=1
print(sum_num)
