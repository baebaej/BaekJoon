a,b,c=map(int,input().split())

if b>=c:
    print(-1)
else:
    benefit=c-b
    res=int(a/benefit)+1
    print(res)
