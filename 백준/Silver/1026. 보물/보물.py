n=int(input())
A=input()
B=input()
A=A.split()
B=B.split()

A=list(map(int,A)) #리스트의 문자형 원소를 int형으로 변환
B=list(map(int,B))

A.sort()
B.sort(reverse=True)
#print(A)
#print(B)

sum=0
for i in range(n):
    sum+=A[i]*B[i]
print(sum)
