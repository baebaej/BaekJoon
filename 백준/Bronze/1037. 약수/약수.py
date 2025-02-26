a=int(input())
b=input()

b=b.split()
b_list=[]
for i in range(a):
    b_list.append(int(b[i]))
b_list.sort(reverse=True)



print(b_list[0] * b_list[a-1])
