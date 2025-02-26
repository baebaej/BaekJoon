nm = input().split()
n=int(nm[0]) #방의 크기
m=int(nm[1])

rcd = input().split()
#로봇청소기 위치 좌표
r=int(rcd[0])
c=int(rcd[1])
#로봇청소기가 바라보는 방향. d가 0이면 북, 1이면 동, 2면 남, 3이면 서쪽
d=int(rcd[2])

Map = []
for i in range(n):
    Map.append(input().split())


#print('로봇 위치:', r, c)
#print('로봇 방향:', d)

#print(Map)

cnt = 0

#Map의 값이 0이면 청소안됨, 1이면 벽, 2면 청소됨

while True:
    #현재 칸이 아직 청소되지 않은 경우 현재 칸을 청소한다.
    if Map[r][c] == '0':
        #print('1번째 if문')
        Map[r][c] = '2'
        cnt=cnt+1
        

    #현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    if  Map[r-1][c] == '0' or Map[r][c-1] == '0' or Map[r+1][c] == '0' or Map[r][c+1] == '0':
        #print('2번째 if문')
        d=d-1 #반시계 방향으로 90도 회전
        if d==-1:
            d=3
        #바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
        if d==0:
            if Map[r-1][c] == '0':
                r=r-1
                continue
        elif d==1:
            if Map[r][c+1] == '0':
                c=c+1
                continue
        elif d==2:
            if Map[r+1][c] == '0':
                r=r+1
                continue
        elif d==3:
            if Map[r][c-1] == '0':
                c=c-1
                continue
        #print('앞쪽이 청소되지 않은 빈 칸이 아님')
        continue

    #현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
    else:
        #print('3번째 if문')
        if d==0:
            if Map[r+1][c] == '1':
                #print('1이동할 수 없습니다. 종료합니다.')
                break
            else:
                r=r+1
                continue
        elif d==1:
            if Map[r][c-1] == '1':
                #print('2이동할 수 없습니다. 종료합니다.')
                #print("마지막 위치 : ", r,c)
                break
            else:
                c=c-1
                continue
        elif d==2:
            if Map[r-1][c] == '1':
                #print('3이동할 수 없습니다. 종료합니다.')
                break
            else:
                r=r-1
                continue
        elif d==3:
            if Map[r][c+1] == '1':
                #print('4이동할 수 없습니다. 종료합니다.')
                break
            else:
                c=c+1
                continue


print(cnt)

#print(Map)

