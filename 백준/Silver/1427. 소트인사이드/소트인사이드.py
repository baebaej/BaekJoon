n=input()
N=[]
for i in range(len(n)):
    N.append(n[i])
N.sort()
N.reverse()
for i in range(len(n)):
    print(N[i],end='')
