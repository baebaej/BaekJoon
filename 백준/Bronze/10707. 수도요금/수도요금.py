a=int(input())
b=int(input())
c=int(input())
d=int(input())
p=int(input())

price_x=0
price_y=0

price_x=a*p

price_y+=b
if p>c:
    price_y+=(p-c)*d

print(min(price_x, price_y))
