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
###########################1541########################
###########################1541########################
###########################11047########################
###########################11000########################

