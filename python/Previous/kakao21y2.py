###########################6번

# def solution(board, skill):
#     answer = 0
#     types={1:-1,2:1}
#     arr=[]
#     for i in board:
#         arr.extend(i)
#     n=len(board)
#     m=len(board[0])
#     for type, r1, c1, r2, c2, degree in skill:
#         row=r2-r1+1
#         col=c2-c1+1
#         # print(r1,c1,r2,c2)
#         for i in range(row):
#             start=m*(r1+i)+c1
#
#             end=start+col
#             # print(start,end)
#             for k in range(start,end):
#                 arr[k]+=degree*types[type]
#
#         # print(arr)
#
#     return len([i for i in arr if i>0])

    # for type,r1,c1,r2,c2,degree in skill:
    #
    #     for i in range(r1,r2+1):
    #         for j in range(c1,c2+1):
    #             board[i][j]+=degree*types[type]
    # n=len(board)
    # m=len(board[0])
    # for i in range(n):
    #     for j in range(m):
    #         if board[i][j]>0:
    #             answer+=1
# print(solution([[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]],[[1,0,0,3,4,4],[1,2,0,2,3,2],[2,1,0,3,1,2],[1,0,1,3,3,1]]))
# print(solution([[1,2,3],[4,5,6],[7,8,9]],[[1,1,1,2,2,4],[1,0,0,1,1,2],[2,2,0,2,0,100]]))

# def solution(board, skill):
#     answer = 0
#     types={1:-1,2:1}
#
#     for type,r1,c1,r2,c2,degree in skill:
#         for i in range(r1,r2+1):
#             for j in range(c1,c2+1):
#                 board[i][j]+=degree*types[type]
#     n=len(board)
#     m=len(board[0])
#     for i in range(n):
#         for j in range(m):
#             if board[i][j]>0:
#                 answer+=1
#     return answer
###########################5번
# import copy
# from collections import deque
#
#
# def dfs(info,children):
#     answer=0
#
#     q=deque()
#     q.append([0,1,0,children[0]])
#     while q:
#         now,sheep,wolf,nexts=q.popleft()
#         if len(nexts)==0:
#             continue
#         answer=max(answer,sheep)
#         for child in nexts:
#             nsheep=sheep;nwolf=wolf
#             tempChilds=copy.deepcopy(nexts)
#             tempChilds.remove(child)
#             nextChilds=copy.deepcopy(children[child])
#             nextChilds.extend(tempChilds)
#
#             if info[child]==0:
#                 nsheep+=1
#             elif info[child]==1:
#                 nwolf+=1
#             if nsheep<=nwolf:
#                 nsheep=0
#             q.append([child,nsheep,nwolf,nextChilds])
#     return answer
#
# def solution(info, edges):
#     n=len(info)
#     children = [[] for i in range(n)]
#     for p,c in edges:
#         children[p].append(c)
#     return bfs(info,children)
#
#
# print(solution([0,0,1,1,1,0,1,0,1,0,1,1],[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))
# print(solution([0,1,0,1,1,0,1,0,0,1,0],[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[4,8],[6,9],[9,10]]))
#

# import copy
#
#
# def dfs(children, now, sheep, wolf):
#     global answer
#
#     if len(children[now]) == 0:
#         return
#
#     for child in children[now]:
#         # print("child before ",children[now])
#         temp = copy.deepcopy(children)
#         temp[now].remove(child)
#         added = copy.deepcopy(temp[now])
#         temp[child].extend(added)
#         temp[now] = []
#         nsheep=sheep;nwolf=wolf
#         if infos[child] == 0:
#             nsheep =sheep+1
#         elif infos[child] == 1:
#             nwolf=wolf+1
#         if nsheep <= nwolf:
#             nsheep = 0
#         # print("child after ",children[now])
#         answer=max(answer,sheep)
#         dfs(temp, child, nsheep, nwolf)
# def solution(info, edges):
#     global answer
#     global infos
#     answer = 1
#     infos=copy.deepcopy(info)
#     n=len(info)
#     visit=[-1]*n
#
#     child=[[] for i in range(n)]
#     for p,c in edges:
#         child[p].append(c)
#
#     dfs(child, 0, 1, 0)
#     return answer

    # q=deque()
    # q.append([0,1,0])
    # while q:
    #     now,sheep,wolf=q.popleft()
    #     print(now,sheep,wolf)
    #     for nextNode in child[now]:
    #         if info[nextNode]==0:
    #             sheep+=1
    #         else:
    #             wolf+=1
    #         if sheep<=wolf:
    #             sheep=0
    #         answer=max(sheep,answer)
    #         q.append([nextNode,sheep,wolf])

# print(solution([0,0,1,1,1,0,1,0,1,0,1,1],[[0,1],[1,2],[1,4],[0,8],[8,7],[9,10],[9,11],[4,3],[6,5],[4,6],[8,9]]))
# print(solution([0,1,0,1,1,0,1,0,0,1,0],[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6],[3,7],[4,8],[6,9],[9,10]]))

###########################4번
# import math
#
#
# def getList(n):
#     d=[[0]*]
#
# def solution(n, info):
#     answer = []
#     return answer
#########################3번
# import math
#
#
# def duration(entrance,exit):
#     inH,inM=map(int,entrance.split(":"));outH,outM=map(int,exit.split(":"))
#     ret=(60+outM-inM)+(outH-1-inH)*60
#     return ret
#
# duration("18:59","23:59")
#
#
# def solution(fees, records):
#     baseTime,baseFee,unitTime,unitFee=fees
#     entrance={}
#     usageTime={}
#     for i in records:
#         time,carNumber,inOut=i.split()
#         if inOut=="IN":
#             entrance[carNumber]=time
#         elif inOut=="OUT":
#             entranceTime=entrance[carNumber]
#             dur=duration(entranceTime,time)
#             car=int(carNumber)
#             usageTime[car]=usageTime.get(car,0)+dur
#             del entrance[carNumber]
#
#     #남아있는거 처리
#     for car,time in entrance.items():
#         dur=duration(time,"23:59")
#         car=int(car)
#         usageTime[car] = usageTime.get(car, 0) + dur
#
#     answer = list(usageTime.items())
#     answer.sort(key=lambda x:x[0])
#
#     answerFee=[]
#     for _,time in answer:
#         if time<=baseTime:
#             answerFee.append(baseFee)
#             continue
#
#         fee=baseFee+math.ceil((time-baseTime)/unitTime)*unitFee
#         answerFee.append(fee)
#
#     return answerFee
# print(solution([180, 5000, 10, 600],["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 \
# IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]))
# print(solution([120, 0, 60, 591],["16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"]))
# print(solution([1, 461, 1, 10],["00:00 1234 IN"]))
################
###########################2번
# import math
# import string
#
# tmp = string.digits+string.ascii_lowercase
# def convert(n, k) :
#     q, r = divmod(n, k)
#     if q == 0 :
#         return tmp[r]
#     else :
#         return convert(q, k) + tmp[r]
#
#
# def isPrime(x):
#     for i in range(2, int(math.sqrt(x)) + 1):
#         if x % i == 0:
#             return False
#     return True
# def solution(n, k):
#     answer = 0
#     num=convert(n,k)
#     arr=num.split("0")
#
#     arr=[int(i) for i in arr if i!='']
#     arr=[i for i in arr if i!=1]
#     print(arr)
#     for i in arr:
#         if isPrime(i)==True:
#             print(i)
#             answer+=1
#
#     # maxValue=max(arr)
#     #
#     # isPrime=erato(maxValue)
#     # for i in arr:
#     #     if isPrime[i]==True:
#     #         answer+=1
#
#     return answer
# print(solution(437674,3))
# print(convert(1000000,3))
# print(solution(1221121211,10))
# def erato(n):
#     arr=[1]*(n+1)
#     arr[1],arr[0]=False,False
#     for i in range(2,int(math.sqrt(n))+1):
#         j=2
#         while j*i<=n:
#             arr[i*j]=False
#             j+=1
#     return arr
# def solution(id_list, report, k):
#     user={}
#     n=len(id_list)
#     for i in range(n):
#         user[id_list[i]]=i
#     q=set(report)
#
#
#     reports=[[] for _ in range(n)]
#     vills=[0]*n
#     answer =[0]*n
#
#     for i in q:
#         reporter,vill=i.split()
#         villIndex=user[vill]
#         reports[villIndex].append(reporter)
#         vills[villIndex]+=1
#
#     for i in range(n):
#         if vills[i]>=k:
#             for j in reports[i]:
#                 answer[user[j]]+=1
#
#     return answer
#
# print(solution(["muzi", "frodo", "apeach", "neo"],["muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"],2))
# print(solution(["con", "ryan"],["ryan con", "ryan con", "ryan con", "ryan con"],3))