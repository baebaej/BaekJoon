def first(node , i):
    if node[i]=='.':
        return
    print(node[i], end='')
    try:
        a=node.index(node[i+1], i+2)
        b=node.index(node[i+2], i+3)
        #print(a,b)
        first(node, a)
        first(node, b)
    except:
        None

def middle(node , i):
    if node[i]=='.':
        return
    try:
        a=node.index(node[i+1], i+2)
        b=node.index(node[i+2], i+3)
        #print(a,b)
        middle(node, a)
        print(node[i], end='')
        middle(node, b)
    except:
        print(node[i], end='')

def last(node , i):
    if node[i]=='.':
        return
    try:
        a=node.index(node[i+1], i+2)
        b=node.index(node[i+2], i+3)
        #print(a,b)
        last(node, a)
        last(node, b)
    except:
        None
    print(node[i], end='')

n=int(input()) # 이진 트리의 노드의 개수
node_tmp=[]
for i in range(n):
    tmp = input().split()
    node_tmp.append(tmp)

node= sum(node_tmp,[]) #2차원배열을 1차원 배열로 변환
#print(node)

first(node, 0)
print()
middle(node, 0)
print()
last(node, 0)
