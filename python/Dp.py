##################################11722
##################################11722
##################################11722
##################################11722
# n=int(input())
# arr=list(map(int,input().split()))
# d=[0]*n;
# for i in range(n):
#     max_v=0
#     for j in range(i):
#         if arr[j]>arr[i]:
#             max_v=max(max_v,d[j])
#     d[i]=max_v+1
# print(max(d));

###################################2293
###################################2293
###################################2293
###################################2293
# import sys
# input=sys.stdin.readline
# n,k=map(int,input().split())
# d=[0]*(k+1)
# d[0]=1
# coins=[int(input()) for _ in range(n)]
#
# for i in coins:
#     for j in range(i,k+1):
#         d[j]+=d[j-i]
#
#
# print(d[k])


# #####################################2294
# import sys
# input=sys.stdin.readline
# n,k=map(int,input().split())
# coins=[int(input()) for _ in range(n)]
# d=[100000]*(k+1)
# d[0]=0
# for i in range(k+1):
#     for j in coins:
#         if i-j>=0:
#             d[i]=min(d[i],d[i-j]+1)
# if d[k]==100000:
#     print(-1)
# else:
#     print(d[k])


# #######################################1912
# n=int(input())
# arr=list(map(int,input().split()))
# d=[0]*(n+1)
#
# for i in range(n):
#     d[i+1]=max(arr[i],arr[i]+d[i])
# print(max(d[1:]))
#

#######################################13398

#
# n = int(input())
# arr = list(map(int, input().split()))
# d = [[0, 0] for _ in range(n + 1)]
#
# for i in range(n):
#     d[i + 1][0] = max(d[i][0] + arr[i], arr[i], d[i][1])
#     d[i + 1][1] = max(d[i][1] + arr[i], arr[i])
#
# if n>=2:
#     temp=max(map(max,d[2:]))
#     print(max(temp,d[1][1]))
# else:
#     print(d[1][1])
# #########################################10844
# n=int(input())
# d=[[0]*10 for _ in range(n)]
# for i in range(1,10):
#     d[0][i]=1
#
# for i in range(1,n):
#     for j in range(10):
#         if 0<j<9:
#             d[i][j]=d[i-1][j-1]+d[i-1][j+1]
#             continue
#         elif j==0:
#             d[i][j]=d[i-1][1]
#             continue
#         elif j==9:
#             d[i][j]=d[i-1][8]
#
# print(sum(d[n-1])%int(1e9))

##########################################1562
# def addNumber(i,j,dir):
#     if dir=="left":
#         for k in range(1024):
#             d[i][j][k|(1<<j)]+=d[i-1][j-1][k]
#
#     elif dir=="right":
#         for k in range(1024):
#             d[i][j][k|(1<<j)]+=d[i-1][j+1][k]
#
# n=int(input())
# d=[[[0]*1024 for _ in range(10)] for _ in range(n+1)]
# for i in range(10):
#     d[1][i][1<<i]=1
#
# result=0
# for i in range(2,n+1):
#     # 1<i<9
#     for j in range(0,10):
#         if not (j==0 or (i==2 and j==1)):
#         # if j!=0:
#             addNumber(i,j,"left")
#         if j!=9:
#             addNumber(i,j,"right")
#
# for i in range(10):
#     result+=d[n][i][1023]
# print(result%1000000000)

#########################################11066
import sys
input=sys.stdin.readline
MAX=int(1e9)
def get_result():
    n= int(input())
    arr = list(map(int, input().split()))
    d=[[0]*n for _ in range(n)]
    sum=[0]
    for i in arr:
        sum.append((sum[-1]+i)) ###################### index - 1 활용
    for dist in range(1,n): #요소 사이의 거리
        for i in range(n-dist):
            j=dist+i
            d[i][j]=MAX
            for k in range(i,j):
                d[i][j]=min(d[i][j],d[i][k]+d[k+1][j]+sum[j+1]-sum[i])
    return d[0][n-1]



n=int(input())
for _ in range(n):

    print(get_result())


#########################################11060\
# n=int(input())
# arr=list(map(int,input().split()))
# d=[1000]*n
# q=[]
# d[0]=0
# def bfs():
#     for i in range(n):
#         dist=arr[i]
#         for j in range(i+1,i+dist+1):
#             if j<n :
#                 d[j]=min(d[j],d[i]+1)
#
#     if d[n-1]==1000:
#         return -1
#     else:
#         return d[n-1]
# print(bfs())
