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
# from collections import deque
# import sys
# import math
# input=sys.stdin.readline
# MAX=int(1e4)
# MIN=int(1e3)
#
#
# def change_one_digit(number,digit,i):
#     left=number[:digit]
#     right=number[digit+1:]
#     return int(left+str(i)+right)
# # print(change_one_digit('1234',3,9))
# isPrime=[True]*(MAX)
# isPrime[0]=False
# isPrime[1]=False
# def is_prime_num():
#     end=int(math.sqrt(MAX))
#     for i in range(2,end):
#         if isPrime[i]==False: continue
#         j = 2
#         k = i * j
#         while k < MAX:
#             isPrime[k] = False
#             j += 1
#             k = i * j
# # print(isPrime)
# def get_result(first,second):
#     d = [0] * (MAX - MIN)
#     visit=[False]*(MAX-MIN)
#     q=deque()
#     q.append(first)
#     visit[first-MIN]=True
#     while q:
#         num=q.popleft()
#         if num==second:
#             break
#         for digit in range(4):
#             for i in range(10):
#                 if digit==0 and i==0: continue
#                 temp=change_one_digit(str(num),digit,i)
#                 if visit[temp-MIN]==False and isPrime[temp]==True:
#                     d[temp-MIN]=d[num-MIN]+1
#                     q.append(temp)
#                     visit[temp-MIN]=True
#
#     return d[second-MIN]
#
# # print(get_result(1373,8017))
#
# n=int(input())
# testcase= [list(map(int,input().split())) for _ in range(n)]
# is_prime_num() #에라토스의 체
# for case in testcase:
#     print(get_result(case[0],case[1]))

# print(testcase)

#################################9019
# import sys
# from collections import deque
# input=sys.stdin.readline
# MAX=int(1e4)
# def cal(number,motion):
#     if motion=='D':
#         return (number*2)%MAX
#     elif motion=='S':
#         return (number-1)%MAX
#     elif motion=='L':
#         q=number//1000
#         remainder=number%1000
#         return remainder*10+q
#     elif motion=='R':
#         q = number // 10
#         remainder = number % 10
#         return remainder * 1000 + q
#
# # print(cal(0,'S'))
#
# # print(cal(1000,'L'))
# # print(cal(1234,'L'))
# # print(cal(1,'R'))
# # print(cal(1234,'R'))
#
# def get_result(i,o):
#     visit=[False]*MAX
#     q=deque()
#
#     q.append((i,''))
#     while q:
#         now,string=q.popleft()
#         if now==o:
#             return string
#         for m in motion:
#             temp=cal(now,m)
#             if visit[temp]==False:
#                 q.append((temp,string+m))
#                 visit[temp]=True
#
# motion=['D','S','L','R']
# # print(get_result(1,16))
# n=int(input())
# data=[list(map(int,input().split())) for _ in range(n)]
# for case in data:
#     print(get_result(case[0],case[1]))
#


#################################1525
#################################2251
from collections import deque

def bfs():
    while q:
        x,y,z=q.popleft()
        if visit[x][y]==True: continue
        if x==0: result[z]=True
        visit[x][y]=True
        #a->b

        if x+y>b: q.append((x+y-b,b,z))
        else : q.append((0,x+y,z))
        #b->c
        if y+z>c: q.append((x,y+z-c,c))
        else : q.append((x,0,y+z))
        #c->a
        if z+x>a: q.append((a,y,z+x-a))
        else : q.append((z+x,y,0))
a,b,c=map(int,input().split())
visit=[[False]*(201) for _ in range(201)]
q=deque()
q.append((0, 0, c))
result=[False]*201
bfs()
for i in range(201):
    if result[i]==True: print(i,end=' ')
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