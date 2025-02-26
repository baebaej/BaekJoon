a,b,v=input().split()
a=int(a)
b=int(b)
v=int(v)

day_distance = a-b
if (v-a)%day_distance ==0:
    print(int((v-a)/day_distance + 1))
else:
    print(int((v-a)/day_distance + 2))
