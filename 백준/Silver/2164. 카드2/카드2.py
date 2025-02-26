n=int(input())
card=[]

for i in range(1,n+1):
    card.append(i)
#print(card)
j=0
while card[j]!=0:
    if n==1:
        break
    if j %2==0:
        #print('삭제',j,card[j])
        card[j]=0
    else:
        #print('맨뒤로 옮기기',j,card[j])
        card.append(card[j])
        card[j]=0
    #print(j,card)
    #print(card[len(card)-2])
    if card[len(card)-2]==0:
        break
    j+=1
#print(card)
length=len(card)
print(card[length-1])
