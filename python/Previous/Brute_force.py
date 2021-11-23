#####################1963 소수경로



##################9019 DSLR
# from collections import deque
# import sys
# input=sys.stdin.readline
# t=int(input())
# def bfs(a,b):
#     q=deque()
#     q.append(["",a])
#     visit=[False]*10000
#     d=['D','S','L','R']
#     while q:
#         route,now=q.popleft()
#         if now==b:
#             return route
#
#         for i in d:
#             temp=now
#             nextString=""
#             if i=='D':
#                 nowInt = int(now)
#                 nextInt=nowInt*2%10000
#                 nextString="000"+str(nextInt)
#                 nextString=nextString[-4:]
#
#             elif i=='S':
#                 nowInt = int(now)
#                 nextInt=(nowInt-1)%10000
#                 nextString="000"+str(nextInt)
#                 nextString=nextString[-4:]
#             elif i=='L':
#                 nextString=temp[1:]+temp[:1]
#             elif i=='R':
#                 nextString=temp[-1:]+temp[:-1]
#
#             index=int(nextString)
#             if visit[index]==False:
#                 q.append([route+i,nextString])
#                 visit[index]=True
#
# for _ in range(t):
#     a,b=input().split()
#     a="000"+a;b="000"+b
#     a=a[-4:];b=b[-4:]
#
#     answer=bfs(a,b)
#     print(answer)

##################1525 퍼즐
# from collections import deque
#
# arr=[list(input().split()) for _ in range(3)]
# data=[]
# for i in arr:
#     data.extend(i)
# string=''.join(data)
#
# dy=[0,0,1,-1]
# dx=[1,-1,0,0]
#
# def bfs(string):
#     q=deque()
#     q.append([0,string])
#     visit = set([string])
#     while q:
#         dist,now=q.popleft()
#         if now=='123456780':
#             return dist
#         index=now.index('0')
#         cy=index//3;cx=index%3
#         for i in range(4):
#             ny=cy+dy[i];nx=cx+dx[i]
#             nIndex=ny*3+nx
#             if 0<=ny<3 and 0<=nx<3 :
#                 nIndex=ny*3+nx
#                 nextString=list(now)
#                 nextString[index],nextString[nIndex]=nextString[nIndex],nextString[index]
#                 nextString=''.join(nextString)
#                 if nextString not in visit:
#                     q.append([dist + 1, nextString])
#                     visit.add(nextString)
#     return -1
#
# print(bfs(string))
###################2251 물통
# from    collections import deque
# a,b,c=map(int,input().split())
# q=deque()
# q.append([0,0,c])
# visit=[[False]*(201) for _ in range(201)]
# answer=[]
# while q:
#     x,y,z=q.popleft()
#     if visit[x][y]==True:
#         continue
#     visit[x][y]=True
#     if x==0:
#         answer.append(z)
#
#     if x+y>b: q.append([x+y-b,b,z])
#     else: q.append([0,x+y,z])
#     if x+z>c: q.append([x+z-c,y,c])
#     else: q.append([0,y,x+z])
#     if y+z>c: q.append([x,y+z-c,c])
#     else: q.append([x,0,y+z])
#     if y+x>a: q.append([a,y+x-a,z])
#     else: q.append([x+y,0,z])
#     if z+x>a: q.append([a,y,x+z-a])
#     else: q.append([z+x,y,0])
#     if z+y>b: q.append([x,b,z+y-b])
#     else: q.append([x,y+z,0])
# answer.sort()
# print(*answer)

###################2186 문자판
# #########################1번째
# import sys
# input=sys.stdin.readline
# n,m,k=map(int,input().split())
# arr=[list(input().rstrip()) for _ in range(n)]
# word=input().rstrip()
# answer=0
# length=len(word)
# d=[[[-1]*length for i in range(m)] for _ in range(n)]
# dy=[1,-1,0,0]
# dx=[0,0,1,-1]
# def dfs(y,x,idx):
#     if y<0 or y>=n or x<0 or x>=m or arr[y][x]!=word[idx]:
#         return 0
#
#     if d[y][x][idx]!=-1:
#         return d[y][x][idx]
#     if idx==length-1:
#
#         d[y][x][idx]=1
#         return d[y][x][idx]
#     d[y][x][idx]=0
#     for i in range(4):
#         for j in range(1,k+1):
#             ny=y+dy[i]*j;nx=x+dx[i]*j
#             d[y][x][idx]+=dfs(ny,nx,idx+1)
#
#     return d[y][x][idx]
#
# starts=[]
# for i in range(n):
#     for j in range(m):
#         if arr[i][j]==word[0]:
#             starts.append([i,j])
# for y,x in starts:
#     answer+=dfs(y,x,0)
# print(answer)
# #########################2번째
# arr=[]
# import sys
# input=sys.stdin.readline
# n,m,k=map(int,input().split())
# arr=[list(input()) for _ in range(n)]
# keyValue=input().rstrip()
# starts=[[i,j] for i in range(n) for j in range(m) if arr[i][j]==keyValue[0]]
# visit=[[[-1]*len(keyValue) for _ in range(m)] for i in range(n)]
# dy=[0,0,1,-1]
# dx=[1,-1,0,0]
# def dfs(y,x,idx):
#     if idx==len(keyValue)-1:
#         return 1
#     if visit[y][x][idx]!=-1:
#         return visit[y][x][idx]
#
#     visit[y][x][idx]=0
#     for i in range(4):
#         for j in range(1,k+1):
#             ny=y+dy[i]*j; nx=x+dx[i]*j
#             if 0<=ny<n and 0<=nx<m and arr[ny][nx]==keyValue[idx+1]:
#                 visit[y][x][idx]+=dfs(ny,nx,idx+1)
#
#     return visit[y][x][idx]
#
# answer=0
# for y,x in starts:
#     answer+=dfs(y,x,0)
# print(answer)

# from collections import deque


# startList=[[i,j] for i in range(n) for j in range(m) if arr[i][j]==keyValue[0]]
#
# answer=0
# dy=[0,0,1,-1]
# dx=[1,-1,0,0]
# visit=[[[-1]*len(keyValue) for _ in range(m)] for i in range(n)]
#
# def dfs(y,x,idx):
#     if idx==len(keyValue)-1:
#         return 1
#     if visit[y][x][idx]!=-1:
#         return visit[y][x][idx]
#     visit[y][x][idx]=0
#     for i in range(4):
#         for j in range(1, k + 1):
#             ny = y + dy[i] * j
#             nx = x + dx[i] * j
#             if 0 <= ny < n and 0 <= nx < m and keyValue[idx + 1] == arr[ny][nx]:
#                 visit[y][x][idx]+=dfs(ny,nx,idx+1)
#
#     return visit[y][x][idx]
#
#
# for y,x in startList:
#     answer+=dfs(y,x,0)
#
# print(answer)
####################3108 로고
# import sys
# input=sys.stdin.readline
# from collections import deque
#
# n=int(input())
# arr=[[0]*2001 for _ in range(2001)]
# starts=[]
# visit=[[False]*2001 for _ in range(2001)]
# dy=[1,-1,0,0]
# dx=[0,0,1,-1]
# def paint(x1,y1,x2,y2):
#     for i in range(x1,x2+1):
#         arr[y1][i]=1
#         arr[y2][i]=1
#     for i in range(y1,y2+1):
#         arr[i][x1]=1
#         arr[i][x2]=1
# for _ in range(n):
#     x1,y1,x2,y2=map(int,input().split())
#     x1=(x1+500)*2;y1=(y1+500)*2;x2=(x2+500)*2;y2=(y2+500)*2;
#     paint(x1,y1,x2,y2)
#     starts.append([x1,y1])
# def bfs(y,x):
#     q=deque()
#     q.append([y,x])
#     visit[y][x]=True
#     while q:
#         cy,cx, = q.popleft()
#
#         for i in range(4):
#             ny=cy+dy[i];nx=cx+dx[i]
#             if 0<=ny<2001 and 0<=nx<2001 and arr[ny][nx]==1 and visit[ny][nx]==False:
#                 q.append([ny,nx])
#                 visit[ny][nx]=True
#
#
# answer=0
# for x,y in starts:
#     if visit[y][x]==False:
#         bfs(y,x)
#         answer+=1
#
# if arr[1000][1000]==1:
#     answer-=1
# print(answer)


####################5014 스타트링크
# from collections import deque
#
# f,s,g,u,d=map(int,input().split())
# visit = [False] * (f + 1)
# d = [u, -d]
#
#
# def bfs():
#     q = deque()
#     q.append([0, s])
#     visit[s] = True
#     while q:
#         dist, now = q.popleft()
#         if now == g:
#             return (dist)
#
#         for i in range(2):
#             next = now + d[i]
#             if 0 < next <= f and visit[next] == False:
#                 q.append([dist + 1, next])
#                 visit[next] = True
#
#     return 0
#
# def solution(f,s,g,u,d):
#     if s==g:
#         print(0)
#         return
#     answer=bfs()
#     if answer==0:
#         print('use the stairs')
#         return
#     print(answer)
#
# solution(u,s,g,u,d)
# from collections import deque
#
# f,s,g,u,d=map(int,input().split())
# visit=[False]*(f+1)
# def bfs(s):
#     q=deque()
#     q.append([0,s])
#     visit[s]=True
#     while q:
#         dist,now, = q.popleft()
#         print(dist,now)
#         if now==g:
#             return dist
#         nu=now+u;nd=now-d
#         if nu<=f and visit[nu]==False:
#             q.append([dist+1,nu])
#             visit[nu]=True
#
#         if nd>=1 and visit[nd]==False:
#             q.append([dist+1,nd])
#             visit[nd]=True
#
#     return 0
#
# answer=bfs(s)
# if s==g:
#     print(0)
# elif answer!=0:
#     print(answer)
# else:
#     print("use the stairs")

####################1759 암호 만들기
#조합 사용
# from itertools import combinations
#
# n,m=map(int,input().split())
# data=input().split()
# vowel=['a','e','i','o','u']
# answer=[]
# for i in combinations(data,n):
#     li=list(i)
#     v=0
#     for i in vowel:
#         for j in li:
#             if i==j:
#                 v+=1
#     c=len(li)-v
#     if v==0 or c<2:
#         continue
#     li.sort()
#     pw="".join(li)
#     answer.append(pw)
# answer.sort()
# for i in answer:
# #     print(i)
# # ##################1987 알파벳
# import sys
# from collections import deque
#
# input=sys.stdin.readline
# n,m=map(int,input().split())
# arr=[list(input().rstrip()) for _ in range(n)]
# dy=[1,-1,0,0]
# dx=[0,0,1,-1]
# def bfs():
#     q=set([(arr[0][0],0,0)])
#     answer=0
#     while q:
#         word,cy,cx=q.pop()
#         answer=max(len(word),answer)
#
#
#         for i in range(4):
#             ny=cy+dy[i];nx=cx+dx[i]
#             if 0<=ny<n and 0<=nx<m and arr[ny][nx] not in word:
#                 q.add((arr[ny][nx]+word,ny,nx))
#     return answer
# print(bfs())







# import sys
#
# dy=[1,-1,0,0]
# dx=[0,0,1,-1]
#
# def bfs(y,x):
#     global answer
#     q=set([(y,x,arr[y][x])])
#
#     while q:
#         y,x,ans=q.pop()
#         for i in range(4):
#             ny=y+dy[i];nx=x+dx[i]
#
#             if 0<=ny<n and 0<=nx<m and arr[ny][nx] not in ans:
#                 q.add((ny,nx,ans+arr[ny][nx]))
#                 answer=max(answer,len(ans)+1)
# n,m=map(int,input().split())
# arr=[list(input()) for _ in range(n)]
# answer=1
# bfs(0,0)
# print(answer)
##################6603
# ############combination 이용
# from itertools import combinations
#
# while True:
#     arr=list(map(int,input().split()))
#     k=arr[0]
#     arr=arr[1:]
#     if k==0:
#         break
#     for i in combinations(arr,6):
#         li=list(i)
#         li.sort()
#         print(*li)
#     print()
# ############################1261 알고스팟
# import heapq
#
# m,n=map(int,input().split())
# arr=[list(map(int,input())) for _ in range(n)]
# visit=[[False]*m for _ in range(n)]
# dy=[1,-1,0,0]
# dx=[0,0,1,-1]
# visit[0][0]=True
# q=[]
# heapq.heappush(q,[0,0,0])
# while q:
#     count,y,x=heapq.heappop(q)
#     if y==n-1 and x==m-1:
#         print(count)
#         break
#
#     for i in range(4):
#         ny=y+dy[i];nx=x+dx[i]
#         if 0<=ny<n and 0<=nx<m and visit[ny][nx]==False:
#             heapq.heappush(q,[count+1 if arr[ny][nx]==1 else count,ny,nx])
#             visit[ny][nx]=True


##############################1644 소수의 연속합
#풀이방법==> 에라토스의 체로 소수들 거른다음에 투포인터로 경우의 수 구하기
# import math
#
# n=int(input())
# nums=[True]*(n+1)
# for i in range(2,math.sqrt(n)+1):
#     if nums[i]==False:
#         continue
#     j=2
#     while i*j<n+1:
#         nums[i*j]=False
#         j+=1
# nums[0]=False;nums[1]=False
# data=[x for x in range(n+1) if nums[x]==True]
#
# answer,end,interval=0,0,0
# m=len(data)
# for start in range(m):
#     while end<m and interval<n:
#         interval+=data[end]
#         end+=1
#
#     if interval==n:
#         answer+=1
#
#     interval-=data[start]
# print(answer)

# ##############################1806 부분합
# n,s=map(int,input().split())
# arr=list(map(int,input().split()))
#
# end,interval,answer=0,0,int(1e6)
#
# for start in range(n):
#     while end<n and interval<s:
#         interval+=arr[end]
#         end+=1
#
#     if interval>=s:
#         answer=min(answer,end-start)
#     interval-=arr[start]
#
# if answer==int(1e9):
#     print(0)
# else:
#     print(answer)
#




# n,s=map(int,input().split())
# data=list(map(int,input().split()))
#
# end,interval=0,0
# answer=int(1e9)
# for start in range(n):
#     while end<n and interval<s:
#         interval+=data[end]
#         end+=1
#
#     if interval>=s:
#         answer=min(end-start,answer)
#     interval-=data[start]
# if answer==int(1e9):
#     answer=0
# print(answer)

# ############################2003 수들의 합
# n,s=map(int,input().split())
# arr=list(map(int,input().split()))
#
# end=0
# interval=0
# answer=0
# for start in range(n):
#     while end<n and interval<s:
#         interval+=arr[end]
#         end+=1
#
#     if interval ==s:
#         answer+=1
#     interval-=arr[start]
# print(answer)







# n,m=map(int,input().split())
# data=list(map(int,input().split()))
#
# end=0
# intervalSum=0
# answer=0
# for start in range(n):
#     while end<n and intervalSum<m:
#         intervalSum+=data[end]
#         end+=1
#
#     if intervalSum==m:
#         answer += 1
#     intervalSum-=data[start]
#
# print(answer)



# #########################2309 일곱 난장이
# from itertools import combinations
#
# heights=[int(input()) for _ in range(9)]
# print(heights)
# answer=[]
# for lst in combinations(heights,7):
#     if sum(lst)==100:
#         answer=list(lst)
#         answer.sort()
#         for i in answer:
#             print(i)
#         break

#######################1182 부분수열의 합
# from itertools import combinations
#
# n,s=map(int,input().split())
# arr=list(map(int,input().split()))
# arr1=arr[:len(arr)//2]
# arr2=arr[len(arr)//2:]
# dic1,dic2={},{}
#
#
# answer=0
#
# for k in range(1,len(arr1)+1):
#     for subset in combinations(arr1,k):
#         sumOfSubset=sum(subset)
#         dic1[sumOfSubset]=dic1.get(sumOfSubset,0)+1
#         if sumOfSubset==s:
#             answer+=1
#
#
# for k in range(1,len(arr2)+1):
#     for subset in combinations(arr2,k):
#         sumOfSubset = sum(subset)
#         if sumOfSubset==s:
#             answer+=1
#         answer+=dic1.get(s-sumOfSubset,0)
# print(answer)


# from itertools import combinations
# n,s=map(int,input().split())
# data=list(map(int,input().split()))
# dic={}
# for i in range(1,len(data)+1):
#     for ele in combinations(data,i):
#         temp=sum(ele)
#         dic[temp]=dic.get(temp,0)+1
# print(dic.get(s,0))

######################1208 부분수열의 합2
# from itertools import combinations
# n,s=map(int,input().split())
# a=list(map(int,input().split()))
# first=a[:n//2]
# second=a[n//2:]
# dic1={}
# for i in range(1,len(first)+1):
#     for ele in combinations(first,i):
#         temp=sum(ele)
#         dic1[temp]=dic1.get(temp,0)+1
# answer=dic1.get(s,0)
# dic1[0]=dic1.get(0,0)+1
# for i in range(1,len(second)+1):
#     for ele in combinations(second,i):
#         temp=sum(ele)
#         answer+=dic1.get(s-temp,0)
# print(answer)
# ####################2143 두 배열의 합
#
# t=int(input())
# n=int(input())
# a=map(int,input().split())
# m=int(input())
# b=map(int,input().split())




# import sys
# input=sys.stdin.readline
# t=int(input())
#
# n=int(input())
# alist=list(map(int,input().split()))
# m=int(input())
# blist=list(map(int,input().split()))
#
#
# first = {}
# second = {}
# for start in range(n):
#     intervalSum = 0
#     for end in range(start, n):
#         intervalSum += alist[end]
#         first[intervalSum] = first.get(intervalSum, 0) + 1
#
#
# for start in range(m):
#     intervalSum = 0
#
#     for end in range(start, m):
#         intervalSum += blist[end]
#         second[intervalSum] = second.get(intervalSum, 0) + 1
#
# answer=0
# for _,key in enumerate(first):
#     answer+=first[key]*second.get(t-key,0)
# print(answer)
####################2632 피자판매 (투포인터)
# import sys
# input=sys.stdin.readline
# size=int(input())
# n,m=map(int,input().split())
# a=list(int(input()) for _ in range(n))
# b=list(int(input()) for _ in range(m))
# asum=sum(a)
# bsum=sum(b)
# a*=2
# b*=2
# intervalSum=0
# aset={0:1,asum:1}
# bset={0:1,bsum:1}
# for start in range(n):
#     intervalSum=0
#     for end in range(start,start+n-1):
#         intervalSum+=a[end]
#         if intervalSum>size:

#             break
#         aset[intervalSum]=aset.get(intervalSum,0)+1
#
# for start in range(m):
#     intervalSum=0
#     for end in range(start,start+m-1):
#         intervalSum+=b[end]
#         if intervalSum>size:
#             break
#         bset[intervalSum]=bset.get(intervalSum,0)+1
# answer=0
# for _,key in enumerate(aset):
#     answer+=aset[key]*bset.get(size-key,0)
# print(answer)

####################7453
# import sys
# input=sys.stdin.readline
# n=int(input())
# alist,blist,clist,dlist=[],[],[],[]
# for _ in range(n):
#     a,b,c,d,=map(int,input().split())
#     alist.append(a);blist.append(b);clist.append(c);dlist.append(d)
#
# first={}
# second={}
#
# for a in alist:
#     for b in blist:
#         first[a+b]=first.get(a+b,0)+1
#
#
#
# answer=0
#
# for c in clist:
#     for d in dlist:
#         answer+=first.get(-(c+d),0)
#
# print(answer)

# import sys
#
# input = sys.stdin.readline
# n = int(input())
# alist, blist, clist, dlist = [], [], [], []
#
# for _ in range(n):
#     a, b, c, d = map(int, input().split())
#     alist.append(a); blist.append(b); clist.append(c); dlist.append(d)
#
# ab = {}
# cd = {}
# for a in alist:
#     for b in blist:
#         ab[a + b] = ab.get(a + b, 0) + 1
#
# answer = 0
# for c in clist:
#     for d in dlist:
#         answer += ab.get(-(c + d), 0)
#
# print(answer)

# # ################################3108 로고
# from collections import deque
# dy=[0,0,-1,1]
# dx=[1,-1,0,0]
#
# def bfs(graph,y,x):
#     q=deque()
#     q.append((y,x))
#     visit[y][x]=True
#
#
#     while q:
#         cy,cx=q.popleft()
#
#         for i in range(4):
#             ny=cy+dy[i]
#             nx=cx+dx[i]
#             if 0<=ny<2001 and 0<=nx<2001 and graph[ny][nx]==1 and visit[ny][nx]==False:
#                 visit[ny][nx]=True
#                 q.append((ny,nx))
#
#
# n=int(input())
# graph=[[0]*2001 for _ in range(2001)]
# visit=[[False]*2001 for _ in range(2001)]
#
# start=deque()
# for _ in range(n):
#     y1,x1,y2,x2=map(int,input().split())
#     y1=y1*2+1000
#     x1=x1*2+1000
#     y2=y2*2+1000
#     x2=x2*2+1000
#     for i in range(y1,y2+1):
#         graph[i][x1]=1
#         graph[i][x2]=1
#     for i in range(x1,x2+1):
#         graph[y1][i]=1
#         graph[y2][i]=1
#     start.append((y1,x1))
#
# answer=0
# while start:
#     y,x=start.pop()
#     if visit[y][x]==False:
#         bfs(graph,y,x)
#         answer+=1
#         pass
#
# if visit[1000][1000]==True:
#     answer-=1
# print(answer)




# from collections import deque
# import sys
# input=sys.stdin.readline
# n=int(input())
# s=[[(0,0,0,0)]]
#
# def bfs(graph,cy,cx):
#     q=deque()
#     q.append([cy,cx])
#     visit[cy][cx]=True
#     while q:
#         cy, cx = q.popleft()
#
#         for i in range(4):
#             ny = cy + dy[i]
#             nx = cx + dx[i]
#             if 0 <= ny < 2001 and 0 <= nx < 2001 and graph[ny][nx] == 1 and visit[ny][nx] == False:
#                 visit[ny][nx] = True
#                 q.append([ny, nx])
#
# graph=[[0]*(2001) for _ in range(2001)]
# visit=[[False]*(2001) for _ in range(2001)]
# lst=[]
# q=deque()
# dy=[0,0,1,-1]
# dx=[1,-1,0,0]
# for _ in range(n):
#     y1,x1,y2,x2=map(int,input().split())
#     y1=y1*2+1000
#     x1=x1*2+1000
#     y2=y2*2+1000
#     x2=x2*2+1000
#     for i in range(y1,y2+1):
#         graph[i][x1]=1
#         graph[i][x2]=1
#     for i in range(x1,x2+1):
#         graph[y1][i]=1
#         graph[y2][i]=1
#     lst.append([y1,x1])
# answer=0
# for cy,cx in lst:
#     if visit[cy][cx]==False:
#         bfs(graph,cy,cx)
#         answer+=1
# if visit[1000][1000]==True:
#     answer-=1
# print(answer)
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


#################################1525  ####2차원 좌표 1차원 변형
# from collections import deque
# n=''
# for _ in range(3):
#     temp=input().split()
#     n+="".join(temp)
#
#     # return string[:s]+string[f]+string[s+1:f]+string[s]+string[f+1:]
# # print(change_location('012345678',6,1))
# q=deque()
# q.append(n)
#
# dist=dict()
# dist[n]=0
#
# dy=[1,-1,0,0]
# dx=[0,0,1,-1]
#
# def get_result():
#     while q:
#         now = q.popleft()
#         if now == '123456780': return dist[now]
#
#
#         index = now.find('0')
#         y,x=index//3,index%3            #1차원을 2차원 좌표로 변환하기
#
#         for i in range(4):
#             ny=y+dy[i]
#             nx=x+dx[i]
#             if 0<=nx<3 and 0<=ny<3:
#                 nIndex=3*ny+nx
#                 ns=list(now)
#                 ns[index],ns[nIndex]=ns[nIndex],ns[index]
#                 ns="".join(ns)
#                 if not dist.get(ns):
#                     dist[ns]=dist[now]+1
#                     q.append(ns)
#     return -1
#
#
#
# print(get_result())
#################################2251
# from collections import deque
#
# def bfs():
#     while q:
#         x,y,z=q.popleft()
#         if visit[x][y]==True: continue
#         if x==0: result[z]=True
#         visit[x][y]=True
#         #a->b
#
#         if x+y>b: q.append((x+y-b,b,z))
#         else : q.append((0,x+y,z))
#         #b->c
#         if y+z>c: q.append((x,y+z-c,c))
#         else : q.append((x,0,y+z))
#         #c->a
#         if z+x>a: q.append((a,y,z+x-a))
#         else : q.append((z+x,y,0))
# a,b,c=map(int,input().split())
# visit=[[False]*(201) for _ in range(201)]
# q=deque()
# q.append((0, 0, c))
# result=[False]*201
# bfs()
# for i in range(201):
#     if result[i]==True: print(i,end=' ')
#################################2186
# import  sys
# sys.setrecursionlimit(10000)
#
# input=sys.stdin.readline
#
# n,m,k=map(int,input().split())
# board=[list(input().rstrip()) for _ in range(n)]
# word=input().rstrip()
# length=len(word)
# dy=[1,-1,0,0]
# dx=[0,0,1,-1]
#
# memo=[[[-1]*length for _ in range(m)] for _ in range(n)]
# # print(board)
# # print(word)
# def get_count(dist,cy,cx):
#     if dist==length-1: return 1
#     if memo[cy][cx][dist]!=-1:
#         return memo[cy][cx][dist]
#     result=0
#     for i in range(4):
#         for j in range(1,k+1):
#             ny=cy+j * dy[i]
#             nx=cx+j * dx[i]
#             if 0<=ny<n and 0<=nx<m and board[ny][nx]==word[dist+1]:
#                 result+=get_count(dist+1,ny,nx)
#
#     return result
#
# # print(get_count(0,3,1))
# result=0
# for i in range(n):
#     for j in range(m):
#         if board[i][j]==word[0]:
#             result+=get_count(0,i,j)
# print(result)
#



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