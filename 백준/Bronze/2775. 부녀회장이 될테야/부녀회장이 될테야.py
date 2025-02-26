T=int(input())
i=0
case=[]
while i< T:
    a=int(input())
    b=int(input())
    case.append(a)
    case.append(b)
    i+=1
#print(case)


i=1
j=0
while i<=T*2:
    apt1=[]
    apt2=[1]
    k=0
    while k<case[i]:
        apt1.append(k+1)
        k+=1
    #print(apt1)
    #print(i, T)

    for p in range(case[j]):
        m=0
        buf=1
        while m<case[i]-1:
            #print('apt1[m]+apt1[m+1]',apt1[m]+apt1[m+1])
            buf+=apt1[m+1]
            apt2.append(buf)
            m+=1
        apt1=apt2.copy()
        apt2=[1]
        #print('apt1',apt1, 'apt2',apt2)
    j+=2
    i+=2
    
    print(apt1[len(apt1)-1])
