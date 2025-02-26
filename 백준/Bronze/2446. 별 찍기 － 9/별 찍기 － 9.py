n=int(input())

for i in range(n,0,-1):
    for j in range(n-i):
        print(end=' ')
    for k in range(i*2-1):
        print('*',end='')
    print()

for i in range(2,n+1):
    for j in range(n-i):
        print(end=' ')
    for k in range(i*2-1):
        print('*',end='')
    print()
