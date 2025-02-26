size=input()
size=size.split()
size.sort()

N=int(size[0])
M=int(size[1])

#print(N,M)

count=0

count+=N-1

count=count+(M-1)*N

print(count)
