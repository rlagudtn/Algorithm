#######################1021 회전하는 큐
from collections import deque

n,m=map(int,input().split())
order=list(map(int,input().split()))
q=[i for i in range(1,n+1)]


def moveLeft(q,d):
    return q[d:]+q[:d]
def moveRight(q,d):
    return q[-d:]+q[:-d]

answer=0
for i in order:

    index=q.index(i)
    size=len(q)
    right=size-index
    if index<right:
        q=moveLeft(q,index)
        answer+=index
    else:
        q=moveRight(q,right)
        answer+=right

    q.pop(0)
print(answer)