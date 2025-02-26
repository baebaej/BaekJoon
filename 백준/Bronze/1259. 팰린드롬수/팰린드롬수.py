while True:
    res='yes'
    a=input()
    if a=='0':
        break
    length=len(a)
    for i in range(len(a)//2):
        if a[i]!=a[len(a)-1-i]:
            res='no'
            break
    print(res)
