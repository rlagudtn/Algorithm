#########################GREEDY#############

#######################1753번 최단경로(다익스트라)
import sys

import heapq
from collections import deque
input=sys.stdin.readline
INF=int(1e9)
v,e=map(int,input().split())
s=int(input())
graph=[[] for _ in range(v+1)]
for _ in range(e):
    a,b,c=map(int,input().split())
    graph[a].append((b,c))

d=[INF]*(v+1)
d[s]=0
q=[]
q.append((0,s))
answer=0
while q:
    dist,now=heapq.heappop(q)
    if dist>d[now]:
        continue

    for i in graph[now]:
        cost=dist+i[1]
        if cost<d[i[0]]:
            d[i[0]]=cost
            heapq.heappush(q,(cost,i[0]))

for i in range(1,v+1):
    if d[i]==INF:
        print('INF')
    else:
        print(d[i])



# ############1449 수리공 항승
# n,l=map(int,input().split())
# arr=[0]*1001
# for i in list(map(int,list(input().split()))):
#     arr[i]=1
#
# count=0
# temp=0
# def seal(length,i):
#     k=i
#     while k<1001 and k<i+length:
#         arr[k]=0
#         k+=1
# i=1
# while i<1001:
#     if arr[i]==1:
#         seal(i,l)
#         count+=1
#         i+=l
#         continue
#     i+=1
# print(count)


# #############1783번 병든 나이트
# n,m=map(int,input().split())
# if n==1:
#     print(1)
# elif n==2:
#     ret=(m+1)//2
#     print(min(4,ret))
# else:
#     if m<7:
#         print(min(4,m))
#     else:
#         print(m-2)
# #########1080번 행렬
# import sys
# input=sys.stdin.readline
# n,m=map(int,input().split())
# arr1=[]
# arr2=[]
#
# for _ in range(n):
#     arr1.append(list(map(int,list(input().rstrip()))))
# for _ in range(n):
#     arr2.append(list(map(int,list(input().rstrip()))))
# answer=0
# def change(arr,y,x):
#     for i in range(y,y+3):
#         for j in range(x,x+3):
#             arr[i][j]=1-arr[i][j]
#
# for i in range(n-2):
#     for j in range(m-2):
#         if arr1[i][j]!=arr2[i][j]:
#             change(arr1,i,j)
#             answer+=1
#
# nonReulst = False
# for i in range(n):
#     for j in range(m):
#         if arr1[i][j] != arr2[i][j]:
#             nonReulst = True
#
# if(nonReulst):
#     print(-1)
# else:
#     print(answer)
# #2217번 #21.03.01
# import sys
# input=sys.stdin.readline
# n=int(input())
# data=[int(input().rstrip()) for _ in range(n)]
# # print(data)
# data.sort(reverse=True)
# result=0
# for i in range(n):
#     result=max(result,(i+1)*data[i])
# print(result)

# ## 11399번   #21.03.01
# n=int(input())
# data=list(map(int,input().split()))
#
# # 1.데이터 오름차순 정렬
# data.sort()
# # 2.데이터 순회하며 합 구해줌
# total=0
# for i in range(n):
#     total+=data[i]
#     data[i]=total
# # 3. 전체합 출력
# print(sum(data))

###########################1931########################
# import sys
# input=sys.stdin.readline
# n=int(input())
# data=[tuple(map(int,input().split())) for _ in range(n)]
#
# # 1.끝시간, 시작을 오름차순으로 정렬한다
# data.sort(key=lambda x:(x[1],x[0]))
#
# # 2.현재시간을 초기화한다
# current=0
# result=0
# # 3.데이터를 순회한다
# for i in data:
#     start,end=i
#     if start>=current:
#         current=end
#         result+=1
# print(result)
# # 개수를 출력한다


# 2. 플러스 만큼 숫자 반복하며 숫자 더해줌
# ###########################1541########################
# string=input()
# nums=[]
# signs=[]
# temp=''
# length=len(string)
# for i in range(length):
#     if i>=length-1:
#         temp+=string[i]
#         nums.append(int(temp))
#     if string[i].isnumeric():
#         temp+=string[i];
#     else:
#         signs.append(string[i])
#         nums.append(int(temp))
#         temp = ""
# def get_result():
#     temp_s = nums[0]
#     size = len(signs)
#     data=[]
#     for i in range(size+1):
#         if i>=size:
#             data.append(temp_s)
#             break
#         if signs[i] == '-':
#             data.append(temp_s)
#             temp_s=nums[i+1]
#         elif signs[i] == '+':
#             temp_s += nums[i+1]
#     size_d=len(data)
#     result=data[0]
#     for i in range(1,size_d):
#         result-=data[i]
#     return result
# print(get_result())
# list=['2','3']
# e=[ sum(list(map(int,x.split('+')))) for x in input().split('-')]
# print(e[0]-sum(e[1:]))
###########################11047########################
# import sys
# input=sys.stdin.readline
# n,k=map(int,input().split())
# coins=[int(input()) for _ in range(n)]
# # print(coins)
# coins.sort(reverse=True)
# result=0
#
# for i in coins:
#
#     result+=k//i
#     k=k%i
# print(result)

###########################1946########################
# import sys
# input=sys.stdin.readline
#
# t=int(input())
#
# for _ in range(t):
#     n=int(input())
#     s=[0]*(n+1)
#     for i in range(n):
#         a,b=map(int,input().split())       ####튜플을 만들지 않고 하는 방법 tech
#         s[a]=b
#     min_n=s[1]
#     count=0 #탈락인원
#     for i in range(2,n+1):
#         if s[i]>min_n: #탈락하는 경우
#             count+=1
#         else: min_n=s[i]
#     print(n-count)
###########################11000########################
###답안 참고했음==>아이디어==>시간복잡도 만족을 위해 우선순위 큐를 사용
# import sys
# import heapq
# input=sys.stdin.readline
#
# n=int(input())
# arr=[list(map(int,input().split())) for _ in range(n)]
# arr.sort(key=lambda x:x[0])
#
# q=[]
# heapq.heappush(q,arr[0][1])
# for i in range(1,n):
#     if q[0]<=arr[i][0]: #
#         heapq.heappop(q)
#
#     heapq.heappush(q,arr[i][1])
#
# print(len(q))
