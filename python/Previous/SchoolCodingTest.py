# elice.io 사이트

#####################1번  구현 문제
# import sys
# input= sys.stdin.readline
# n=int(input())
# data=[]
# for _ in range(n):
#     tempList=[int(x) for x in input().split()] ########입력받는 방식
#     data.append(tempList)
#
# data.sort()
# result=0
# for arrive,wait in data:
#     if arrive>result:
#         result=arrive
#     else: result+=wait
#
# print(result)

#####################2번 그리디 문제
# import sys
# input= sys.stdin.readline
# n,m=map(int,input().split())
# p=1000
# o=1000
# for _ in range(m):
#     tempP,tempO=map(int,input().split())
#     p=min(p,tempP)
#     o=min(o,tempO)
#
# if p>6*o:
#     p=6*o
#
# if((n%6)*o>p):
#     print(n//6*p+p)
# else:
#     print(n//6*p+n%6*o)

##################4번 문제 ##정렬
# import sys
# input=sys.stdin.readline().rstrip
#
# n=int(input())
# data=[]
# for _ in range(n):
#     temp=input()
#     sum=0
#     for i in temp:
#         if i.isdigit():
#             sum+=int(i)
#     data.append((len(temp),sum,temp))
#
# data=sorted(data,key=lambda x:(x[0],x[1],x[2]))
#
# for _,_,serial in data:
#     print(serial)

######################5번 ##bfs/dfs
# import sys
# input=sys.stdin.readline
# from itertools import combinations
# arr=list(map(int,input().split()))
# n=arr[0]
# result=[]
# for i in combinations(arr[1:],n):
#     for j in combinations(i,5):
#         result.append(j)
#
# print(result)



#
import sys
from collections import deque
input=sys.stdin.readline
n=int(input())
graph=[]
for _ in range(n):
    graph.append(list(map(int,input().rstrip())))
print(graph)