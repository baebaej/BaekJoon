m=[]
while True:
    a,b,c=input().split()
    a=int(a)
    b=int(b)
    c=int(c)
    if a==0 and b==0 and c==0:
        break
    m.append(a)
    m.append(b)
    m.append(c)

i=0
while i<len(m):
    x=m[i]
    y=m[i+1]
    z=m[i+2]
    if y>x and y>z:
        x=buf
        x=y
        y=buf
    elif z>x and z>y:
        buf=x
        x=z
        z=buf
    if z*z+y*y==x*x:
        print('right')
    else:
        print('wrong')
    i+=3
