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
