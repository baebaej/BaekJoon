a,b,c=map(int,input().split())
d=int(input())

c+=d
while c>=60:
    b+=1
    c-=60
    if b>=60:
        a+=1
        b-=60
    if a>=24:
        a=0
        b=0

print(a,b,c)
