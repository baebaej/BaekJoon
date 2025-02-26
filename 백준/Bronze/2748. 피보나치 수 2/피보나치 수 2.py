n=int(input())

first=0
second=1
for i in range(n):
    summary=first+second
    first=second
    second=summary
print(first)
