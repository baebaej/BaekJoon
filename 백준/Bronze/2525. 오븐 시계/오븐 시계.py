a,b=input().split()
a=int(a)
b=int(b)
c=int(input())

b+=c
while b>=60:
    a+=1
    b-=60
    if a>23:
        a=0
print(a,b)
