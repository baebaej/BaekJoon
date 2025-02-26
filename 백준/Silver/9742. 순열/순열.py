def perm(case, i):
    global status
    global count
    j=0
    global perm_cases
    while i+j<len(case):
        case = list(case)
        case[i], case[i+j] = case[i+j], case[i] #치환
        if j!=0:
            count+=1
            #print(count, perm_cases)

            if n==count and status == False:
                perm_cases = case
                #print('찾음', perm_cases)
                status = True
            
        if n>count: #찾으려는 번호가 현재 찾은 번호보다 크면
            #print('count', count)
            perm(case, i+1) #재귀함수
        j+=1

while True:
    try:
        inp = input().split()
        case=inp[0]
        global n
        n=int(inp[1])
        
        perm_cases = ''
        count = 1
        status = False  #탐색 여부
        
        perm(case, 0) #함수 호출

        if n ==1 :
            print(case, n, '=', ''.join(case))
        elif perm_cases=='':
            print(case, n, '= No permutation')
        elif n>1:
            print(case, n, '=', ''.join(perm_cases))

    except:
        exit()
