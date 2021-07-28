##################1916 최소비용 구하기
import heapq
import sys
INF=int(1e9)
input=sys.stdin.readline
n=int(input())
m=int(input())
graph=[[] for _ in range(n+1)]
for _ in range(m):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))

start,end=map(int,input().split())


def dijkstra(graph, start, end):
    q=[]
    d=[INF]*(n+1)
    d[start]=0
    heapq.heappush(q,(0,start))
    while q:
        dist,now=heapq.heappop(q)
        if d[now]<dist:
            continue

        for next,c in graph[now]:
            cost=d[now]+c
            if cost<d[next]:
                d[next]=cost
                heapq.heappush(q,(cost,next))

    return d[end]


print(dijkstra(graph,start,end))

##################백준 1238 파티 ====>역으로 어떻게 하는지 기억할 것
# import sys
# input=sys.stdin.readline
# import heapq
#
# INF=int(1e9)
# n,m,x=map(int,input().split())
# adj=[[] for _ in range(n+1)]
# re_adj=[[] for _ in range(n+1)]
#
#
# def dijkstra(graph,start):
#     q=[]
#     d=[INF]*(n+1)
#     d[start]=0
#     heapq.heappush(q,(0,start))
#
#     while q:
#         dist,now=heapq.heappop(q)
#         if dist>d[now]:
#             continue
#
#         for i in graph[now]:
#             cost=i[1]+d[now]
#             if cost<d[i[0]]:
#                 d[i[0]]=cost
#                 heapq.heappush(q,(cost,i[0],))
#
#     return d[1:]
#
# for _ in range(m):
#     a,b,cost=map(int,input().split())
#     adj[a].append((b,cost))
#     re_adj[b].append((a,cost))
#
# print(max([a+b for a,b in zip(dijkstra(adj,x),dijkstra(re_adj,x))]))



