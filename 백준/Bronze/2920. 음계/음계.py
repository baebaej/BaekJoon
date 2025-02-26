n = [int(x) for x in input().strip().split()]
length=len(n)
cnt1=0
cnt2=0
for i in range(length-1):
    if n[i]<n[i+1]:
        cnt1+=1
    elif n[i]>n[i+1]:
        cnt2+=1
if cnt1==length-1:
    print('ascending')
elif cnt2==length-1:
    print('descending')
else:
    print('mixed')
