s=input()
length=len(s)
#print(chr(97))
for j in range(26):
    search=0
    #print(chr(j+97),end=' ')
    for i in range(length):
        if s[i]==chr(j+97):
            print(i,end=' ')
            search=1
            break
    if search==0:
        print('-1',end=' ')

