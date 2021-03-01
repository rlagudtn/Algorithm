import sys
from collections import Counter
input=sys.stdin.readline
n,m=map(int,input().split())
data=[input().rstrip() for _ in range(n)]
result=dict()
for word in data:
    if word not in result:
        result[word]=1
    else: result[word]+=1

temp=[]
for word in result.items():
    w=word[0]
    temp.append((word[1],len(w),w))
temp.sort(key=lambda x:(-x[0],-x[1],x[2]))

print([x[2] for x in temp if x[1]>=m])
    # temp.append(word.value,word.key)
# print(result)


# counts=dict()
#
# for _ in range(n):
#     temp=input().rstrip()
#     if temp not in counts: counts[temp]=1
#     else: counts[temp]+=1
#     if len(temp)<m: continue
#     data.append((counts[temp],len(temp),temp))
#
# # print(data)
# result=set()
# dic=sorted(data,key=lambda x:(-x[0],-x[1],x[2]))
# for word in dic:
#     if word[2] not in result: result.add(word[2])
# for ret in result:
#     print(ret)

##################C번
# import sys
# from collections import deque
# input=sys.stdin.readline
#
# n,m=map(int,input().split())
# d=deque()
# s=deque()
# for _ in range(n):
#     td,ts=map(int,input().split())
#     d.appendleft(td)
#     s.appendleft(ts)
# #
# i=0
# gd=deque()
# gs=deque()
#
# # print(s)
# # gs.extend(s)
# # print(gs)
# turn=0
# td=0
# ts=0
# while d and s :
#     if turn ==0:
#         td=d.popleft()
#         gd.append(td)
#         turn=1
#     else:
#         ts = s.popleft()
#         gs.append(ts)
#         turn=0
#     i+=1
#
#     if i>=m: break
#     if td!=5 and ts!=5 and ts+td!=5: continue
#
#     elif (td!=0 and ts!=0 and td+ts==5):
#         s.extend(gd)
#         s.extend(gs)
#
#     else:
#         d.extend(gs)
#         d.extend(gd)
#     gd.clear()
#     gs.clear()
#     ts = 0
#     td = 0
#
#
# countS=len(s)
# countD=len(d)
# if countS==countD: print('dosu')
# elif countS>countD: print('su')
# else: print('do')