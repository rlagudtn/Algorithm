#####################1707
from collections import deque

t=int(input())
def bfs(edges,visit):
    q=deque()
    q.append(1)
    visit[1]=0
    while q:
        now=q.popleft()
        for i in edges[now]:
            if visit[i]!=-1 and visit[i]==visit[now]:
                return False
            elif visit[i]==-1:
                visit[i]=1-visit[now]
                q.append(i)
    return True

for _ in range(t):
    v,e=map(int,input().split())
    edges=[[] for _ in range(v+1)]
    visit=[-1]*(v+1)
    for i in range(e):
        s,e=map(int,input().split())
        edges[s].append(e)
        edges[e].append(s)
    answer=bfs(edges,visit)
    if answer==True:
        print("YES")
    else:
        print("NO")

#####################10451
# import sys
# input=sys.stdin.readline
# t=int(input())
# def dfs(arr,visit,v):
#     if visit[v]==True:
#         return
#     visit[v]=True
#     dfs(arr,visit,arr[v])
#
# for _ in range(t):
#     n=int(input())
#     data=list(map(int,input().split()))
#     arr=[0]*(n+1)
#     for i in range(len(data)):
#         arr[i+1]=data[i]
#
#     visit=[False]*(n+1)
#     answer=0
#     for i in range(1,n+1):
#         if visit[i]==False:
#             dfs(arr,visit,i)
#             answer += 1
#
#     print(answer)


###################11724
# import sys
#
# def bfs(s):
#     q=deque()
#     q.append(s)
#     visit[s]=True
#     while q:
#         now=q.popleft()
#         for node in graph[now]:
#             if visit[node]==False:
#                 q.append(node)
#                 visit[node]=True
#
# from collections import deque
# input=sys.stdin.readline
# n,m=map(int,input().split())
# graph=[[] for _ in range(n+1)]
#
# for _ in range(m):
#     a,b=map(int,input().split())
#     graph[a].append(b)
#     graph[b].append(a)
# visit=[False]*(n+1)
# answer=0
# for i in range(1,n+1):
#     if visit[i]==False:
#         bfs(i)
#         answer+=1
# print(answer)
# ####################1260 dfs와 bfs
# import sys
# from collections import deque
# input=sys.stdin.readline
# n,m,s=map(int,input().split())
# graph=[[] for _ in range(n+1)]
# for _ in range(m):
#     a,b=map(int,input().split())
#     graph[a].append(b)
#     graph[b].append(a)
#
# for i in range(1,n+1):
#     graph[i].sort()
#
# visitD=[False]*(n+1)
# visitB=[False]*(n+1)
# def dfs(s):
#     if visitD[s]==True:
#         return
#     visitD[s]=True
#     print(s,end=" ")
#     for node in graph[s]:
#         dfs(node)
# def bfs(s):
#     q=deque()
#     q.append(s)
#     visitB[s]=True
#     while q:
#         now=q.popleft()
#         print(now,end=" ")
#
#         for node in graph[now]:
#             if visitB[node]==False:
#                 q.append(node)
#                 visitB[node]=True
#
# dfs(s)
# print()
# bfs(s)






# #################2468
# from collections import deque
# n=int(input())
# arr=[]
# max_value=0
# for _ in range(n):
#     lst=list(map(int,input().split()))
#     max_value=max(max_value,max(lst))
#     arr.append(lst)
# def getArea(n,height):
#     #특정높이 이하 색칠
#     temp=[[0]*n for _ in range(n)]
#     for i in range(n):
#         for j in range(n):
#             if arr[i][j]<=height:
#                 temp[i][j]=1
#
#     pass
#     dy=[0,0,1,-1]
#     dx=[1,-1,0,0]
#     def dfs(y,x):
#         global n
#         stack = deque()
#         stack.append([y,x])
#         while stack:
#             cy,cx=stack.pop()
#             for i in range(4):
#                 ny=cy+dy[i]
#                 nx=cx+dx[i]
#                 if 0<=ny<n and 0<=nx<n and temp[ny][nx]==0:
#                     temp[ny][nx]=1
#                     stack.append([ny,nx])
#
#     cnt=0
#     for i in range(n):
#         for j in range(n):
#             if temp[i][j]==0:
#                 dfs(i,j)
#                 cnt+=1
#     return cnt
# ret=0
# for k in range(0,max_value+1):
#     ret=max(ret,getArea(n,k))
# print(ret)
# ####################2178 미로탐색
# # from collections import  deque
# # n,m=map(int,input().split())
# # arr=[list(map(int,list(input()))) for _ in range(n)]
# # v=[[0]*m for _ in range(n)]
# #
# # v[0][0]=1
# #
# # q=deque()
# #
# # q.append([0,0,1])
# #
# # dy=[0,0,1,-1]
# # dx=[1,-1,0,0]
# #
# # while q:
# #     y,x,cnt=q.popleft()
# #
# #     if y==n-1 and x==m-1:
# #         print(cnt)
# #         break
# #
# #     for i in range(4):
# #         ny=y+dy[i]
# #         nx=x+dx[i]
# #         if ny < 0 or ny >= n or nx < 0 or nx >= m or v[ny][nx]==1 or arr[ny][nx]==0:
# #             continue
# #
# #         v[ny][nx]=1
# #         q.append([ny,nx,cnt+1])
#
#
#
#
