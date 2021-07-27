
import sys
input=sys.stdin.readline
import heapq


def findParent(parent,now):
    if parent[now]!=now:
        parent[now]=findParent(parent,parent[now])
    return parent[now]

def union(parent,a,b):
    a=findParent(parent,a)
    b=findParent(parent,b)
    if a<b:
        parent[b]=a
    else:
        parent[a]=b
###########################백준 6497 전력난
while True:
    m, n = map(int, input().split())
    if m==0 and n==0:
        break
    parent = [i for i in range(m)]
    q = []
    sum_value = 0
    for _ in range(n):
        x, y, cost = map(int, input().split())
        heapq.heappush(q, (cost, x, y))
        sum_value += cost
    count = 0
    answer = 0
    while q:
        cost, x, y = heapq.heappop(q)

        if findParent(parent, x) == findParent(parent, y):
            continue

        union(parent, x, y)
        answer += cost
        count += 1
        if count == n - 1:
            break

    print(sum_value - answer)


#
# #########################백준 2887 행성 터널
# n=int(input())
# planets=[]
# for i in range(1,n+1):
#     x,y,z=map(int,input().split())
#     planets.append((x,y,z,i))
#
# edges=[]
#
# for k in range(3):
#     planets.sort(key=lambda x:x[k])
#     for i in range(n-1):
#         heapq.heappush(edges,(abs(planets[i][k]-planets[i+1][k]),planets[i][3],planets[i+1][3]))
#
# parent=[i for i in range(n+1)]
# count=0
# answer=0
# while edges:
#     cost,now,next=heapq.heappop(edges)
#     if findParent(parent,now)==findParent(parent,next):
#         continue
#
#     union(parent,now,next)
#     answer+=cost
#     count+=1
#     if count==n-1:
#         break
# print(answer)



#########################백준 1647번 도시분할 계획
# n,m=map(int,input().split())
# q=[]
# parent=[i for i in range(n+1)]
#
# for _ in range(m):
#     a,b,cost=map(int,input().split())
#     heapq.heappush(q,(cost,a,b))
#
# count=0
# answer=0
# while q:
#     cost,a,b=heapq.heappop(q)
#     if findParent(parent,a)==findParent(parent,b):
#         continue
#
#     union(parent,a,b)
#     answer+=cost
#     count+=1
#     if count==n-2:
#         break
# print(answer)
###########################크루스칼 백준 1922
# n=int(input())
# m=int(input())
# q=[]
# parent=[i for i in range(n+1)]
#
# for _ in range(m):
#     a,b,cost= map(int,input().split())
#     heapq.heappush(q,(cost,a,b))
#
# q.sort()
#
# answer=0
# count=0
# while q:
#     cost,a,b=heapq.heappop(q)
#     if findParent(parent,a)==findParent(parent,b):
#         continue
#     union(parent, a, b)
#     answer += cost
#     count += 1
#
#     if count==n-1:
#         break
#
# print(answer)



