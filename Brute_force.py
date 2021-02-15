#################################147
#################################1107
#################################1451
#################################9095
#################################10819
# from itertools import permutations
# n=int(input())
# data=list(map(int,input().split()))
# result=0
# for case in permutations(data,n):
#     s=0
#     for i in range(n-1):
#         s+=abs(case[i]-case[i+1])
#     result=max(result,s)
# print(result)

#################################10971
# import sys
# from itertools import permutations
# input=sys.stdin.readline
# INF=int(1e9)
# n=int(input())
# graph=[list(map(int,input().split())) for _ in range(n)]
# numbers=[i for i in range(n)]
# def get_route_sum(path):
#     result=0
#     for i in range(n-1):
#         edge=graph[path[i]][path[i+1]]
#         if edge==0: return 0
#         result+= edge
#     edge=graph[path[n-1]][path[0]]
#     if edge==0: return 0
#     result+=edge
#     return result
#
# result= int(1e7)
# for case in permutations(numbers,n):
#     temp=get_route_sum(case)
#     if temp==0: continue
#     result=min(result,temp)
#
# print(result)


#################################1697
# from collections import deque
# n,k=map(int,input().split())
#
# q=deque()
# d=[0]*(100001)
# # print(d)
# if k<=n: print(n-k)
# else:
#     q.append((n,0))
#     while q:
#         now,dist=q.popleft()
#         if now>100000 or now<0: continue
#         if d[now]==0:
#             d[now]=dist
#         elif d[now]!=0 and d[now]<=dist: continue
#         else: d[now]=dist
#
#         if now == k: break
#         q.append((now+1,dist+1))
#         q.append((now*2,dist+1))
#         q.append((now-1,dist+1))
#     print(d[k])
#


#################################1963
################1963#################9019
#################################1525
#################################2251
#################################2186
#################################3108
#################################5014
#################################1759
#################################2580
#################################1987
#################################6603
#################################1182
#################################2003
#################################1806
#################################1644
#################################1261
#################################1208
#################################7453
#################################2632
#################################2143
#################################