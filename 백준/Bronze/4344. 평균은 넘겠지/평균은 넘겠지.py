c=int(input())
score=[]
for i in range(c):
    tmp=input()
    tmp=tmp.split()
    score.append(tmp)
#print(score)

sum=0
for i in range(c):
    for j in score[i]:
        sum+=int(j)
    sum-=int(score[i][0])
    #print(sum)
    avg=sum/int(score[i][0])
    #print(avg)
    count=0
    for k in range(1, int(score[i][0])+1):
        if int(score[i][k])>avg:
            count+=1
    res = count/int(score[i][0])*100
    sum=0
    print("{:.3f}%".format(res))
