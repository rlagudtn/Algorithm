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


#########################################11066
