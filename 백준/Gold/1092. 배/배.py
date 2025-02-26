n=int(input())
limit=list(map(int, input().split()))
m=int(input())
weight = list(map(int, input().split()))
limit.sort(reverse = True)
weight.sort(reverse = True)
#print(limit, weight)

def fun():
    if limit[0]<weight[0]:  #크레인 무게 제한을 초과하는 짐이 있는 경우 -1
        print('-1')
        return

    time = 0
    i=0
    while len(weight)!=0:
        for lim in limit:
            for w in weight:
                if lim>=w:
                    del(weight[i])
                    isPossible = True
                    break
                i+=1
            i=0
        time +=1
        
    print(time)

fun()
