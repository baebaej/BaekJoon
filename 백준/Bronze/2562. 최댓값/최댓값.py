i=0
a=[0]*10
while i<9:
    a[i]=int(input())
    i+=1
i=0
max=0
max_location=0
while i<9:
    if max<a[i]:
        max=a[i]
        max_location=i+1
    i+=1
print(max)
print(max_location)
