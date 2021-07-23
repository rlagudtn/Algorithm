##################점프와 순간이동
def solution(n):
    ans = 0

    while n>=1:
        if n%2==0:
            n//=2
            continue
        n-=1
        ans+=1

    return ans

print(solution(5000))
# #################삼각 달팽이
# import math
# arr=[1,2,3]
# arr.insert(-(1),4)
# arr.insert(0,5)
# def fillAround(arr,start,n,shell):
#     #n과 shell 을 이용해서 범위를 구한다
#     top=2*(shell-1)
#     length=n-3*(shell-1)
#     end=start+3*(length-1)-1
#     left=start+1
#     right=end
#     for i in range(length):
#         if i==0:
#             middle=top//2
#             arr[top].insert(middle,start)
#         elif i==length-1:
#             num=left
#             for j in range(length):
#                 arr[top].insert(shell-1+j,num)
#                 num+=1
#         else:
#             arr[top].insert(-(shell-1),right)
#
#             arr[top].insert(shell-1,left)
#             left+=1
#             right-=1
#         top+=1
#     #위에서부터 채운다.
#     #마지막 숫자를 반환한다.
#     return end
# def solution(n):
#     arr = [[] for _ in range(n)]
#     shells=math.ceil(n/3)
#     start=1
#     for i in range(1,shells+1):
#         end=fillAround(arr,start,n,i)
#         start=end+1
#     return sum(arr,[])
# print(solution(5))
# ###영어 끝말잇기
# def solution(n, words):
#     li=set([])
#     answer=[0,0]
#     now=2
#     turn=1
#     leavingOut=False
#     previous=words[0]
#     li.add(words[0])
#     for i in range(1,len(words)):
#         if now>n:
#             now=1
#             turn+=1
#         if words[i] in li or previous[-1]!=words[i][0] :
#             leavingOut=True
#             break
#         li.add(words[i])
#         previous=words[i]
#         now+=1
#     if leavingOut==True:
#         answer=[now,turn]
#
#     return answer
#
# print(solution(2,["hello", "one", "even", "never", "now", "world", "draw"]))

#######################배달 -->최단 거리 이동
# import heapq
# INF=int(1e9)
# def dijkstra(graph,N,start):
#     q=[]
#     d=[INF]*(N+1)
#     d[start]=0
#     heapq.heappush(q,(0,start))
#
#     while q:
#         dist,now=heapq.heappop(q)
#
#         if d[now]<dist:
#             continue
#
#         for i in graph[now]:
#             cost=dist+i[1]
#             if d[i[0]]>cost:
#                 d[i[0]]=cost
#                 heapq.heappush(q,(cost,i[0]))
#
#     return d
#
# def solution(N, road, K):
#     answer = 0
#     graph=[[] for _ in range(N+1)]
#     for a,b,c in road:
#         graph[a].append((b,c))
#         graph[b].append((a,c))
#     d=dijkstra(graph,N,1)
#
#     result=[i for i in range(1,N+1) if d[i]<=K ]
#
#
#     return len(result)
#
# print(solution(5,[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]],3))
# ###################거리두기 확인하기
# def isSafe(place,y,x):
#     dy=[-1,0,1,0]
#     dx=[0,1,0,-1]
#     diag=[(1,1),(1,-1),(-1,1),(-1,-1)]
#     for i in range(4):
#         for j in range(1,3):
#             ny=y+dy[i]*j
#             nx=x+dx[i]*j
#             if ny<0 or ny>=5 or nx<0 or nx>=5:
#                 break
#             if place[ny][nx]=='P':
#                 return False
#             if place[ny][nx]=='X':
#                 break
#
#         for cy,cx in diag:
#             ny=y+cy
#             nx=x+cx
#             if ny < 0 or ny >= 5 or nx < 0 or nx >= 5:
#                 continue
#             if place[ny][nx]=='P' and not (place[y][nx]=='X' and place[ny][x]=='X'):
#
#                 return False
#
#
#     return True
#
# def keepDistance(place):
#     for i in range(len(place)):
#         for j in range(len(place[0])):
#             if place[i][j]=='O' or place[i][j]=='X':
#                 continue
#             if not isSafe(place,i,j):
#                 return False
#     return True
# def solution(places):
#     answer = []
#     for i in places:
#         if keepDistance(i):
#             answer.append(1)
#         else:
#             answer.append(0)
#     return answer
#
# print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))
# #################예상 대진표
# import math
#
# def solution(n,a,b):
#     answer = 0
#     k=math.log(n,2)
#     n=n//2
#     standard=n
#     count=0
#     while True:
#         n//=2
#         if (a<=standard and b>standard) or (a>standard and b<=standard):
#             break
#         elif a<=standard and b<=standard:
#             standard-=n
#         else:
#             standard+=n
#         count+=1
#
#     answer=k-count
#     return answer


#################게임 맵 최단거리
# from collections import deque
# def bfs(graph):
#     dy=[0,0,-1,1]
#     dx=[1,-1,0,0]
#
#     n=len(graph)
#     m=len(graph[0])
#     visit=[[1]*m for _ in range(n)]
#     q=deque()
#
#     q.append((0,0,1))
#     visit[0][0]=0
#
#     while q:
#         cy,cx,dist=q.popleft()
#         if cy==n-1 and cx==m-1:
#             return dist
#         for i in range(4):
#             ny=cy+dy[i]
#             nx=cx+dx[i]
#
#             if 0<=ny<n and 0<=nx<m and graph[ny][nx]==1 and visit[ny][nx]==1:
#                 visit[ny][nx]=0
#                 q.append((ny,nx,dist+1))
#
#     return -1
#
# def solution(maps):
#     answer = 0
#
#
#
#     return bfs(maps)


# print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,0],[0,0,0,0,1]]	))
###############짝지어 제거하기
# from collections import deque
# def solution(s):
#     answer =1
#     stack=deque()
#
#     for i in range(len(s)):
#         if len(stack)==0:
#             stack.append(s[i])
#             continue
#
#         last=stack.pop()
#         if last==s[i]:
#             continue
#         stack.append(last)
#         stack.append(s[i])
#
#     if len(stack)!=0:
#         answer=0
#     return answer
#
# print(solution("baabaa"))
# print(solution("cdcd"))

# ##############괄호 회전하기
# from collections import deque
# pairLeft={'(':1,'{':2,'[':3}
# pairRight={')':1,'}':2,']':3}
# def isRight(temp):
#
#     stack=deque()
#
#     for i in temp:
#         if i in pairLeft.keys():
#             stack.append(i)
#         else:
#             if len(stack)==0:
#                 return False
#             top=stack.pop()
#             if pairLeft[top]!=pairRight[i]:
#                 return False
#     if len(stack)!=0:
#         return False
#     return True
#
#
# def solution(s):
#     answer = 0
#     for i in range(len(s)-1):
#         first=s[:i]
#         second=s[i:]
#         if isRight(second+first):
#             answer+=1
#     return answer
# print(solution("}}}"))
# #################멀쩡한 사각형
# import math
# def solution(w,h):
#     gcd = math.gcd(w, h)
#     return w*h-(w+h-gcd)
#
#
# print(solution(8,12))
##################추석 트래픽
# def check(li,time):
#     start=time
#     end=time+1000
#     cnt=0
#     for i in li:
#         if i[1]>=start and i[0]<end:
#             cnt+=1
#     return cnt
# def solution(lines):
#     answer = 1
#     li=[]
#     for i in lines:
#         date,time,duration=i.split()
#         h,m,s=time.split(":")
#
#         end=(int(h)*3600+int(m)*60+float(s))*1000
#
#         dur=float(duration.replace("s",""))*1000
#
#         start=end-dur+1
#         li.append([start,end])
#
#     print(li)
#     for i in li:
#         answer=max(answer,check(li,i[0]),check(li,i[1]))
#     return answer
# print(solution([
# "2016-09-15 20:59:57.421 0.351s",
# "2016-09-15 20:59:58.233 1.181s",
# "2016-09-15 20:59:58.299 0.8s",
# "2016-09-15 20:59:58.688 1.041s",
# "2016-09-15 20:59:59.591 1.412s",
# "2016-09-15 21:00:00.464 1.466s",
# "2016-09-15 21:00:00.741 1.581s",
# "2016-09-15 21:00:00.748 2.31s",
# "2016-09-15 21:00:00.966 0.381s",
# "2016-09-15 21:00:02.066 2.62s"
# ]))
######################방금 그곡
# import math
# class Parser:
#     def __init__(self,musicinfo):
#         self.musicInfo=musicinfo
#     def parse(self):
#         time1,time2,name,melody=self.musicInfo.split(',')
#         time=self.parseTime(time1,time2)
#         return time,name,melody
#     def parseTime(self,t1,t2):
#         t1h,t1m=t1.split(':')
#         t2h,t2m=t2.split(':')
#         minutes=int(t2m)-int(t1m)
#         if minutes<0:
#             minutes+=60
#             t2h-=1
#         minutes+=(int(t2h)-int(t1h))*60
#         return minutes
#
#
# def solution(m, musicinfos):
#     answer = None
#     maxValue=0
#     for i in musicinfos:
#         parser=Parser(i)
#         time,name,melody=parser.parse()
#         m_count=len([x for x in melody if x !="#"])
#         if time>m_count:
#             n=time/m_count
#             melody*=math.ceil(n)
#         else:
#             k=0
#             index=0
#             for i in range(len(melody)):
#                 index=i
#                 if melody[i]=="#":
#                     continue
#                 if k==m_count:
#                     break
#                 k+=1
#             melody=melody[:index]
#         if melody.count(m)==0 or melody.count(m)==melody.count(m+"#"):
#             continue
#         if len(melody)>maxValue:
#             maxValue=len(melody)
#             answer=name
#     return answer
# print(solution("ABC",["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
####################캐시######33

# from collections import deque
# def solution(cacheSize, cities):
#     q=deque(maxlen=cacheSize)
#     answer=0
#     for k in cities:
#         i=k.upper()
#         if i in q:
#             q.remove(i)
#             answer+=1
#         else:
#             answer +=5
#         q.append(i)
#
#     return answer
# print(solution(3,	["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]))

###############프렌즈 4블록
# arr=[[0,1,0,2] for _ in range(3)]
# print(arr)
# for i in range(3):
#     arr[i]=[x for x in arr[i] if x!=0]
# print(arr)
# def isSame(board,cy,cx):
#     same=True
#     if cx>=len(board[cy]) or cx+1>=len(board[cy+1]):
#         return False
#     if board[cy+1][cx]!=board[cy][cx]:
#         same=False
#     if board[cy][cx+1]!=board[cy][cx]:
#         same=False
#     if board[cy+1][cx+1]!=board[cy][cx]:
#         same=False
#     return same
#
# def removeSame(board,equals):
#     for cy,cx in equals:
#         board[cy][cx]=0
#         board[cy+1][cx]=0
#         board[cy][cx+1]=0
#         board[cy+1][cx+1]=0
# def removeZero(board):
#     ret=0
#     for i in range(len(board)):
#         before=len(board[i])
#         board[i]=[x for x in board[i] if x!=0]
#         ret+=before-len(board[i])
#     return ret
# def run(board):
#     equals=[]
#     for i in range(len(board)-1):
#         for j in range(len(board[i])-1):
#             if isSame(board,i,j):
#                 equals.append([i,j])
#     removeSame(board,equals)
#
#     return removeZero(board)
# def solution(m, n, board):
#     answer = 0
#     arr=[[0]*m for _ in range(n)]
#     for i in range(m):
#         temp=list(board[i])
#         for j in range(n):
#             arr[j][m-i-1]=temp[j]
#     while True:
#         count=run(arr)
#         if count==0:
#             break
#         answer+=count
#     return answer
# print(solution(6,6,["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]))
####################후보키
# from itertools import combinations
#
# def concat(lst,tup):
#     ret=""
#     for i in tup:
#         ret+=lst[i]
#     return ret
# def solution(relation):
#     answer = 0
#     key=[]
#     num=len(relation)
#     col=len(relation[0])
#     columns=[i for i in range(col)]
#
#     for i in range(1,num+1):
#         for listTup in combinations(columns,i):
#             s=set([])
#             for k in range(num):
#                 temp=concat(relation[k],listTup)
#                 s.add(temp)
#             if(len(s)==num):
#                 isExisted=False
#                 for i in key:
#                     if set(i) < set(listTup): ###########################부분집합 여부 확인
#                         isExisted=True
#                         break
#                 if isExisted==False:
#                     key.append(list(listTup))
#
#     return len(key)
#
# solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]])


######################오픈 채팅방
# def solution(record):
#     answer = []
#     dic={}
#     user=[]
#     commands=[]
#     for i in record:
#
#         lst=i.split()
#     #     dic[id]=nickName
#         if lst[0] =="Leave":
#             user.append(lst[1])
#             commands.append("님이 나갔습니다.")
#             continue
#         elif lst[0]=="Enter":
#             id, nickName = lst[1], lst[2]
#             dic[id] = nickName
#             commands.append("님이 들어왔습니다.")
#         elif lst[0]=="Change":
#             id, nickName = lst[1], lst[2]
#             dic[id] = nickName
#             continue
#         user.append(id)
#     #
#     for i in range(len(user)):
#         answer.append(dic[user[i]]+commands[i])
#     return answer
# print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))
# #####################순위 검색
# import bisect
# class Info:
#     def __init__(self,lan, job, career, food, score):
#         self.lan=lan
#         self.job=job
#         self.career=career
#         self.food=food
#         self.score=int(score)
#     def __str__(self):
#         return "({},{},{},{},{})".format(self.lan,self.job,self.career,self.food,str(self.score))
#     def getAt(self):
#         return self.lan,self.job,self.career,self.food,self.score
# class Parser:
#     def __init__(self,infos,queries):
#         self.infos=infos
#         self.queries=queries
#
#     def parseInfo(self):
#         ret=[]
#         for i in range(len(self.infos)):
#             lan,job,career,food,score=self.infos[i].split()
#             ret.append(Info(lan,job,career,food,score))
#         return ret
#
#     def parseQuery(self):
#         ret = []
#         for i in range(len(self.queries)):
#             lan, job, career, foodAndScore = self.queries[i].split(' and ')
#             food,score=foodAndScore.split()
#
#             ret.append(Info(lan, job, career, food, score))
#         return ret
# def classify(infos,group):
#     for i in infos:
#         lan, job, career, food, score = i.getAt()
#         langs={"-",lan}
#         jobs={"-",job}
#         careers={"-",career}
#         foods={"-",food}
#         for x in langs:
#             for y in jobs:
#                 for z in careers:
#                     for k in foods:
#                         key=x+y+z+k
#                         bisect.insort(group[key],score)
#
#
# def solution(info, query):
#     answer = []
#     group={}
#     parser=Parser(info,query)
#     infos=parser.parseInfo()
#     queries=parser.parseQuery()
#     langs = {"-", "java","cpp","python"}
#     jobs = {"-", "backend","frontend"}
#     careers = {"-", "junior","senior"}
#     foods = {"-", "chicken","pizza"}
#     for x in langs:
#         for y in jobs:
#             for z in careers:
#                 for k in foods:
#                     key = x + y + z + k
#                     group[key]=[]
#     classify(infos,group)
#     for i in queries:
#         lan, job, career, food, score = i.getAt()
#         key=lan+job+career+food
#         size=len(group[key])
#         index=bisect.bisect_left(group[key],score)
#         answer.append(size-index)
#     # print(list(group.items()))
#
#     return answer
#
# sol=solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],\
#          ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"])
# print(sol)
# #####################기능 개발
# def solution(progresses, speeds):
#     answer = []
#     lst=[]
#     for i in range(len(progresses)):
#         remainder=(100-progresses[i])%speeds[i]
#         day=(100-progresses[i])//speeds[i]
#         if remainder!=0:
#             day+=1
#         lst.append(day)
#     work=lst[0]
#     count=1
#     print(lst)
#     for i in range(1,len(lst)):
#         print(i,count)
#         if i == len(lst) - 1:
#             answer.append(count)
#             break
#         if work<lst[i]:
#             answer.append(count)
#             work=lst[i]
#             count=1
#         else:
#             count+=1
#
#
#     return answer
# print(solution([93, 30, 55],[1, 30, 5]))
######################위장
# from collections import Counter
# def solution(clothes):
#     answer = 1
#     kinds=[i[1] for i in clothes]
#     dic=list(Counter(kinds).values())
#     for i in dic:
#         answer*=i+1
#     answer-=1
#     return answer
# print(solution([["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"], ["green_turban", "top"]]))
# print(solution([["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]))
# ############################전화번호 목록
# def solution(phone_book):
#     phone_book.sort()
#     for first,second in zip(phone_book,phone_book[1:]):
#
#         if second.startswith(first):
#             return False
#     return True

# print(solution(["119", "97674223", "1195524421"]))
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
#
# if __name__=="__main__":
#     main()
#
#
# # import sys
# # input=sys.stdin.readline
# # def main():
# #     skills=list(input().split())
# #     n=int(input())
# #     q=[]
# #     for i in range(n):
# #         f,e=input().split()
# #         q.append([f,e])
# #     result=[]
# #
# #         # for data in q:
# #
# #
# #
# # if __name__ == "__main__":
# #     main()
#
# ###########3번
# # import sys
# # input=sys.stdin.readline
# # def main():
# #     p, n, h = map(int, input().split())
# #     times = [h] * (p + 1)
# #     resv = [[] for _ in range(p + 1)]
# #     for _ in range(n):
# #         pc, hours = map(int, input().split())
# #         resv[pc].append(hours)
# #
# #     for pc in resv:
# #         pc.sort(reverse=True)
# #
# #     for i in range(1, p + 1):
# #         hours = 0
# #
# #         for j in resv[i]:
# #             if times[i] >= j:
# #                 times[i] -= j
# #                 hours += j
# #         print(i, hours * 1000)
#
#
# from bisect import bisect_left
# # def main():
# #     n, m, s = map(int, input().split())
# #     data = list(map(int, input().split()))
# #     result = data[-1] - data[0]
# #     end = n - m + 1
# #     for i in range(0, end + 1):
# #         temp = data[i:i + m]
# #         if temp[0] <= s <= temp[-1]:
# #             result = min(result, temp[-1] - temp[0])
# #         elif temp[0] > s:
# #             result = min(result, temp[-1] - s)
# #
# #         else:
# #             result = min(result, s - temp[0])
# #     print(result)
#
# #################4번
# # def main():
# #     n=int(input())
# #     data=list(map(int,input().split()))
# #     result=0
# #     for i in range(3):
# #         visited=[False]*n
# #         visited[i]=True
# #         current=i
# #         count=1
# #         while True:
# #             current += data[current]
# #             count+=1
# #             if current<0 or current>=n:
# #                 result=max(result,current)
# #                 break
# #             if visited[current]==True:
# #                 result=max(result,count)
# #                 break
# #             visited[current]=True
# #     print(result)
# #
#
# # import sys
# # input=sys.stdin.readline
# # n=int(input())
# # n*=n
# # score=[0]*n
# # l=[0]*n
# # up=[[0]*int(1e8) for _ in range(n)]
# # for i in range(n):
# #     temp=list(map(int,input().split()))
# #     score[i]=temp[0]
# #     l[i]=temp[1]
# #     temp=temp[2:]
# #     for j in temp:
# #         print(j)
# #         up[j]=1
# #
# #
# # print(up)
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
# # #########################dfs/bfs#######################
# #
# # #1번
# # # def dfs(array,target,temp_sum,i):
# # #     plus=array[i]+temp_sum
# # #     minus=temp_sum-array[i]
# # #     ret=0
# # #     if i==len(array)-1 :
# # #         if plus==target: return 1
# # #         elif minus==target:return 1
# # #         else: return 0
# # #
# # #     ret+=dfs(array,target,plus,i+1)
# # #     ret+=dfs(array,target,minus,i+1)
# # #     return ret
# # #
# # #
# # # def solution(numbers, target):
# # #     return dfs(numbers,target,0,0)
# #
# #
# # ##################2번 네트워크
# # # def dfs(v,n,computers,visited):
# # #     visited[v]=True
# # #
# # #     for i in range(n):
# # #         if i!=v and visited[i]==False and computers[v][i]==1:
# # #             dfs(i,n,computers,visited)
# # #     pass
# # # def solution(n, computers):
# # #     visited=[False]*n
# # #     answer=0
# # #     for i in range(n):
# # #         #
# # #         if visited[i]==False:
# # #             dfs(i,n,computers,visited)
# # #             answer+=1
# # #     return answer
# # #
# # # print(solution(3,[[1, 1, 0], [1, 1, 1], [0, 1, 1]]))
# #
# # #########################단어 변환####################
# # from collections import deque
# # def oneCharDiffer(first,second):
# #     first=list(first)
# #     second=list(second)
# #     length=len(first)
# #     count=0
# #     for i in range(length):
# #         if first[i]!=second[i]: count+=1
# #         if count>=2: return False
# #     return True
# #
# # # print(oneCharDiffer('ros','los'))
# #
# # def solution(begin, target, words):
# #     length=len(words)
# #     q=deque()
# #     q.append((0,0,begin)) #(id,dist,word)
# #     visited=[False]*(length+1)
# #     while q:
# #         id,dist,now=q.popleft()
# #         print(dist,now)
# #         if now==target: return dist
# #
# #         for i in range(length):
# #             if oneCharDiffer(now,words[i]) and visited[i+1]==False:
# #                 q.append((i+1,dist+1,words[i]))
# #                 visited[i+1]=True
# #
# #     return 0
# #
# # # print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]), 4)
# # # print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]), 0)
# # # print(solution("hit", "hot", ["hot", "dot", "dog", "lot", "log"]), 1)
# # # print(solution("1234567000", "1234567899", [
# # #       "1234567800", "1234567890", "1234567899"]), 3)
# # # # print(solution("hit", "cog", ["cog", "log", "lot", "dog", "hot"]), 4)
# # def solution(citations):
# #     citations.sort(reverse=True)
# #
# #     length = len(citations)
# #     for i in range(length):
# #         if citations[i] < i + 1: return i
# #     return length
# #
# #
# # print(solution([0,0,0]))
#
#
#
#
