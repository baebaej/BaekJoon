n=int(input())

for i in range(1,n+1):
    for j in range(n-i,0,-1):
        print(end=' ')
    for k in range(1,i*2):
        print('*',end='')
    print()
