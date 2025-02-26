a,b=input().split()
a=int(a)
b=int(b)

if b-45<0:
    b=b-45+60
    a=a-1
else:
    b=b-45
if a<0:
    a=23
print(a, b)
