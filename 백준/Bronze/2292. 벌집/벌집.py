n=int(input())

a=1
b=6
i=1
while True:
    a=a+b*i
    if n<=a:
        break
    i+=1
if n==1:
    print(1)
else:
    print(i+1)
