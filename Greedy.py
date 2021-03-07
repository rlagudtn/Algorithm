#########################GREEDY#############

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
list=['2','3']
e=[ sum(list(map(int,x.split('+')))) for x in input().split('-')]
print(e[0]-sum(e[1:]))
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
