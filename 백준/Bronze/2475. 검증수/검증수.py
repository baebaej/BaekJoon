a,b,c,d,e=input().split()
a=int(a)
b=int(b)
c=int(c)
d=int(d)
e=int(e)

square_sum=a*a+b*b+c*c+d*d+e*e
res=square_sum%10
print(res)
