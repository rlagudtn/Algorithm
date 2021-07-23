
# ##################3665번: 최종 순위
# from collections import deque
# def findNode(indegree):
#     for i in range(1,len(indegree)):
#         if indegree[i]==0:
#             return i
#     return 0
# def change(graph,indegree,a,b):
#     if a in graph[b]:
#         graph[b].remove(a)
#         graph[a].append(b)
#         indegree[a]-=1
#         indegree[b]+=1
#     elif b in graph[a]:
#         graph[a].remove(b)
#         graph[b].append(a)
#         indegree[b] -= 1
#         indegree[a] += 1
# def solution(graph,indegree):
#     ret=[]
#     start=findNode(indegree)
#     print(start)
#     q=deque()
#     q.append(start)
#     while q:
#         if len(q)>1:
#             return None
#         now=q.popleft()
#         ret.append(now)
#         for i in graph[now]:
#             indegree[i]-=1
#             if indegree[i]==0:
#                 q.append(i)
#             elif indegree[i]<0:
#                 return None
#     return ret
# t=int(input())
# for _ in range(t):
#     n=int(input())
#     last=list(map(int,input().split()))
#     last.insert(0,0)
#     graph=[[] for _ in range(n+1)]
#     indegree=[0]*(n+1)
#
#     for i in range(1,n):
#         for j in range(i+1,n+1):
#             graph[last[i]].append(last[j])
#             indegree[last[j]]+=1
#
#     m=int(input())
#     changes=[tuple(map(int,input().split())) for _ in range(m)]
#
#     for a,b in changes:
#         change(graph,indegree,a,b)
#     #
#     # ret=solution(graph,indegree)
#     # if ret==None or len(ret)<n:
#     #     print("IMPOSSIBLE")
#     # else:
#     #     print(ret)



# ################1005번: ACM craft
# import sys
# from collections import deque
# input=sys.stdin.readline
# def solution(graph,indegree,n,d,w):
#     time=[0]*(n+1)
#
#     q=deque()
#     for i in range(1,n+1):
#         if indegree[i]==0:
#             q.append(i)
#             time[i]=d[i]
#     result=0
#     while q:
#         now=q.popleft()
#
#         for i in graph[now]:
#             indegree[i]-=1
#             time[i]=max(time[i],time[now]+d[i])
#
#             if indegree[i]==0:
#                 q.append(i)
#     return time[w]
#
# t=int(input())
# ret=[]
# for _ in range(t):
#     n,k=map(int,input().split())
#     d=list(map(int,input().split()))
#     d.insert(0,0)
#     graph=[[] for _ in range(n+1)]
#
#     indegree=[0]*(n+1)
#
#     for i in range(k):
#         a,b=map(int,input().split())
#         graph[a].append(b)
#         indegree[b]+=1
#     w=int(input())
#     ret.append(solution(graph,indegree,n,d,w))
#
# for i in ret:
#     print(i)
#
