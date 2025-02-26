n=int(input())

first=0
second=1

for i in range(n):
    buf=first
    first=second
    second=buf+second
print(first)
