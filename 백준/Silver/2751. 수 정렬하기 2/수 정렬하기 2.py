import sys

n=int(input())
mem=[]
for i in range(n):
    a=int(sys.stdin.readline())
    mem.append(a)
#print('정렬 전',mem)

mem.sort()

for i in range(n):
    print(mem[i])
