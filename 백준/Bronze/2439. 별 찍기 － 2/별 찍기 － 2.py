a=int(input())
i=1
while i<=a:
    for j in range(a-i):
        print(' ',end='')
    for k in range(i):
        print('*',end='')
    print('')
    i+=1
