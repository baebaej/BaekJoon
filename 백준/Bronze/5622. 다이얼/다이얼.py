dialer=[['A','B','C'],['D','E','F'],['G','H','I'],['J','K','L'],['M','N','O'],['P','Q','R','S'],['T','U','V'],['W','X','Y','Z']]

eng_num=input()
time=0
for i in range(len(eng_num)):
    for j in range(len(dialer)):
        if eng_num[i] in dialer[j]:
            res=j+2
            time+=j+3
            break

print(time)
