import sys

n=int(input())

for i in range(n):
    a,b=map(int,sys.stdin.readline().split())
    A=a
    B=b
    while A!=B:
        if A>B:
            B=B+b
        elif A<B:
            A=A+a
    print(A)
