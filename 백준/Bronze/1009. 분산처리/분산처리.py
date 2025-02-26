import sys

t=int(input())

powlist=[[1],[2,4,8,6],[3,9,7,1],[4,6],[5],[6],[7,9,3,1],[8,4,2,6],[9,1],[10]]
for i in range(t):
    a,b=map(int,sys.stdin.readline().split())
    a=a%10
    buf=b%len(powlist[a-1])
    print(powlist[a-1][buf-1])

