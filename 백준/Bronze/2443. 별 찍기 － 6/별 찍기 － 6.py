n=int(input())

for i in range(1,n+1):
    for k in range(i-1):
        print(end=' ')
    for j in range(n*2-(2*i-1)):
        print('*',end='')
    print()
