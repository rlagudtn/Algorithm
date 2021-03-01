import sys
input=sys.stdin.readline
def main():
    p, n, h = map(int, input().split())
    times = [h] * (p + 1)
    resv = [[] for _ in range(p + 1)]
    for _ in range(n):
        pc, hours = map(int, input().split())
        resv[pc].append(hours)

    for pc in resv:
        pc.sort(reverse=True)

    for i in range(1, p + 1):
        hours = 0

        for j in resv[i]:
            if times[i] >= j:
                times[i] -= j
                hours += j
        print(i, hours * 1000)

if __name__=="__main__":
    main()


# import sys
# input=sys.stdin.readline
# def main():
#     skills=list(input().split())
#     n=int(input())
#     q=[]
#     for i in range(n):
#         f,e=input().split()
#         q.append([f,e])
#     result=[]
#
#         # for data in q:
#
#
#
# if __name__ == "__main__":
#     main()

###########3번
# import sys
# input=sys.stdin.readline
# def main():
#     p, n, h = map(int, input().split())
#     times = [h] * (p + 1)
#     resv = [[] for _ in range(p + 1)]
#     for _ in range(n):
#         pc, hours = map(int, input().split())
#         resv[pc].append(hours)
#
#     for pc in resv:
#         pc.sort(reverse=True)
#
#     for i in range(1, p + 1):
#         hours = 0
#
#         for j in resv[i]:
#             if times[i] >= j:
#                 times[i] -= j
#                 hours += j
#         print(i, hours * 1000)


from bisect import bisect_left
# def main():
#     n, m, s = map(int, input().split())
#     data = list(map(int, input().split()))
#     result = data[-1] - data[0]
#     end = n - m + 1
#     for i in range(0, end + 1):
#         temp = data[i:i + m]
#         if temp[0] <= s <= temp[-1]:
#             result = min(result, temp[-1] - temp[0])
#         elif temp[0] > s:
#             result = min(result, temp[-1] - s)
#
#         else:
#             result = min(result, s - temp[0])
#     print(result)

#################4번
# def main():
#     n=int(input())
#     data=list(map(int,input().split()))
#     result=0
#     for i in range(3):
#         visited=[False]*n
#         visited[i]=True
#         current=i
#         count=1
#         while True:
#             current += data[current]
#             count+=1
#             if current<0 or current>=n:
#                 result=max(result,current)
#                 break
#             if visited[current]==True:
#                 result=max(result,count)
#                 break
#             visited[current]=True
#     print(result)
#

# import sys
# input=sys.stdin.readline
# n=int(input())
# n*=n
# score=[0]*n
# l=[0]*n
# up=[[0]*int(1e8) for _ in range(n)]
# for i in range(n):
#     temp=list(map(int,input().split()))
#     score[i]=temp[0]
#     l[i]=temp[1]
#     temp=temp[2:]
#     for j in temp:
#         print(j)
#         up[j]=1
#
#
# print(up)






















# #########################dfs/bfs#######################
#
# #1번
# # def dfs(array,target,temp_sum,i):
# #     plus=array[i]+temp_sum
# #     minus=temp_sum-array[i]
# #     ret=0
# #     if i==len(array)-1 :
# #         if plus==target: return 1
# #         elif minus==target:return 1
# #         else: return 0
# #
# #     ret+=dfs(array,target,plus,i+1)
# #     ret+=dfs(array,target,minus,i+1)
# #     return ret
# #
# #
# # def solution(numbers, target):
# #     return dfs(numbers,target,0,0)
#
#
# ##################2번 네트워크
# # def dfs(v,n,computers,visited):
# #     visited[v]=True
# #
# #     for i in range(n):
# #         if i!=v and visited[i]==False and computers[v][i]==1:
# #             dfs(i,n,computers,visited)
# #     pass
# # def solution(n, computers):
# #     visited=[False]*n
# #     answer=0
# #     for i in range(n):
# #         #
# #         if visited[i]==False:
# #             dfs(i,n,computers,visited)
# #             answer+=1
# #     return answer
# #
# # print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]]))
#
# #########################단어 변환####################
# from collections import deque
# def oneCharDiffer(first,second):
#     first=list(first)
#     second=list(second)
#     length=len(first)
#     count=0
#     for i in range(length):
#         if first[i]!=second[i]: count+=1
#         if count>=2: return False
#     return True
#
# # print(oneCharDiffer('ros','los'))
#
# def solution(begin, target, words):
#     length=len(words)
#     q=deque()
#     q.append((0,0,begin)) #(id,dist,word)
#     visited=[False]*(length+1)
#     while q:
#         id,dist,now=q.popleft()
#         print(dist,now)
#         if now==target: return dist
#
#         for i in range(length):
#             if oneCharDiffer(now,words[i]) and visited[i+1]==False:
#                 q.append((i+1,dist+1,words[i]))
#                 visited[i+1]=True
#
#     return 0
#
# # print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]), 4)
# # print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]), 0)
# # print(solution("hit", "hot", ["hot", "dot", "dog", "lot", "log"]), 1)
# # print(solution("1234567000", "1234567899", [
# #       "1234567800", "1234567890", "1234567899"]), 3)
# # # print(solution("hit", "cog", ["cog", "log", "lot", "dog", "hot"]), 4)
# def solution(citations):
#     citations.sort(reverse=True)
#
#     length = len(citations)
#     for i in range(length):
#         if citations[i] < i + 1: return i
#     return length
#
#
# print(solution([0,0,0]))




