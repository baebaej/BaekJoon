num=int(input())
score = [int(x) for x in input().strip().split()]
max_score=max(score)

for i in range(num):
    score[i]=score[i]/max_score*100

new_sum_score=0
for i in range(num):
    new_sum_score+=score[i]

average=new_sum_score/num
print(average)
