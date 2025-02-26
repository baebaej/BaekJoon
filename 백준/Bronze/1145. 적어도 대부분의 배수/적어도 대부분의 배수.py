num=list(map(int, input().split()))

num.sort()

#print(num)

i=num[0]
count = 0 
while count<3:
    count=0
    for k in num:
        if i % k ==0:
            count+=1
            #print(k, i, "나누어떨어짐")
    i+=1

print(i-1)
