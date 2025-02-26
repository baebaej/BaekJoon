def fib(n):
    fibo=[0,1]
    p=0
    if n>=2:
        for i in range(n):
            fibo.append(fibo[p]+fibo[p+1])
            p+=1
    return fibo

t=int(input())
N=[]
for i in range(t):
    n=int(input())
    N.append(n)
key=max(N)
fibo = fib(key)

for i in N:
    if i>=1:
        print(fibo[i-1], fibo[i])
    else:
        print('1 0')
