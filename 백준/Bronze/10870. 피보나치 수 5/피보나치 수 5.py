n=int(input())
first=0
second=1

for i in range(n):
    buf=first+second
    first=second
    second=buf
print(first)
