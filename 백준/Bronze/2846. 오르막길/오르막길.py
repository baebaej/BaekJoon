size=int(input())
height=input()
height=height.split()

status=False
max_hill=0
i=0
while i<size-1:
    if status==False:
        temp=int(height[i])
    if int(height[i])<int(height[i+1]):
        status=True
    elif int(height[i])>=int(height[i+1]):
        dif=int(height[i])-temp
        if dif>max_hill:
            max_hill=dif;
        status=False
    i+=1
if status==True:
    dif=int(height[size-1])-temp
    if dif>max_hill:
        max_hill=dif;
print(max_hill)
