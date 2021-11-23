# ##################7번
# def rotateLeft60(grid):
#     row=len(grid)
#     answer=[[] for _ in range(row)]
#     for i in range(row):
#         start=(2*i)
#         #첫번째
#         answer[row-i-1].append(grid[i][start])
#         #나머지 n-1
#         for j in range(i+1,row):
#             first=grid[j][start+1];second=grid[j][start]
#             answer[row-i-1].append(first)
#             answer[row-i-1].append(second)
#     return answer
#
# def solution(grid, clockwise):
#     answer = []
#
#     temp=rotateLeft60(grid)
#
#
#     if clockwise==True:
#         temp=rotateLeft60(temp)
#
#     for i in temp:
#         answer.append("".join(i))
#     return answer
# print(solution(["1","234","56789"],	True))
# print(solution(["A","MAN","DRINK","WATER11"],	False))
#
###########6번

# def requiredTime(start,end):
#     FRI_S=9.5;FRI_E=18
#     MON_S=13;MON_E=18
#     friHour=int(start[:-2]);friInfo=start[-2:]
#     monHour=int(end[:-2]);monInfo=end[-2:]
#     if(friInfo=="PM"):
#         friHour+=12
#     if(monInfo=="PM"):
#         monHour+=12
#     ret=0
#     if(FRI_S<=friHour<=FRI_E):
#         ret+=FRI_E-friHour
#     elif(friHour<FRI_S):
#         ret+=FRI_E-FRI_S
#
#     if(MON_E>=monHour>=MON_S):
#         ret+=monHour-MON_S
#     elif(monHour>MON_E):
#         ret+=MON_E-MON_S
#
#     return ret
#
# def solution(time, plans):
#     current='호치민'
#     # answer=current
#     next=current
#     total=0
#     for i in plans:
#         country,start,end=i
#         next=country
#         total+=requiredTime(start,end)
#
#         if (total > time):
#             break
#         else:
#             current=next
#
#
#     return current
# print(solution(0	,[ ["홍콩", "5PM", "9AM"] ]))
#
# print(solution(0	,[ ["홍콩", "5AM", "9AM"], ["엘에이", "3PM", "2PM"] ]))
#
# print(solution(3.5	,[ ["홍콩", "11PM", "9AM"], ["엘에이", "3PM", "2PM"] ]))
# print(solution(18,[["홍콩", "11PM", "9AM"], ["엘에이", "3PM", "2PM"] ]))
# def isAllZero(arr):
#     for i in range(len(arr)):
#         for j in range(len(arr[0])):
#             if(arr[i][j]==0):
#                 return False
#     return True
#
# def solution(rows, columns):
#     arr = [[0]*columns for i in range(rows)]
#
#     latest=1
#     r=c=0
#     arr[0][0]=latest
#     while not isAllZero(arr):
#         if latest%2==1:
#             c+=1
#             if(c>=columns):
#                 c=0
#         else:
#             r+=1
#             if(r>=rows):
#                 r=0
#         latest+=1
#         if latest%2==arr[r][c]%2 and not arr[r][c]==0:
#             break
#         arr[r][c]=latest
#
#     return arr
# print(solution(1000,1000))
#
# print(solution(3,4))
#
# print(solution(3,4))
# print(solution(10,10))
# #
############4번

def solution(s):
    answer = []
    cnt=1
    for i in range(1,len(s)):
        if s[i]!=s[i-1]:
            answer.append(cnt)
            cnt=1
        else:
            cnt+=1
        if i == len(s) - 1:
            answer.append(cnt)
    if(s[0]==s[-1]):
        s=answer[0]+answer[-1]
        answer.pop(-1)
        answer.pop(0)
        answer.append(s)

    answer.sort()
    return answer
print(solution("aaabbaaa"))
print(solution("wowwow"))
print(solution("aaabbaab"))
print(solution("aaabcbbaaa"))
print(solution("acabbaab"))
print(solution("acabbaaa"))
# #
# #
##############3번
# def originPrice(items,ingre):
#     ret=0
#     for i in ingre:
#         ret+=items[i]
#     return ret
# def solution(ings, menu, sell):
#     answer = 0
#     items=dict()
#     menus=dict()
#     #재료 가격
#     for i in ings:
#         k,v=i.split()
#         items[k]=int(v)
#     print(items)
#     #메뉴 가격
#     for i in menu:
#         temp=i.split()
#         gap=int(temp[2])-originPrice(items,temp[1])
#         menus[temp[0]]=gap
#     print(menus)
#     # 구입 내역
#     for i in sell:
#         purchase=i.split()
#         answer+=menus.get(purchase[0],0)*int(purchase[1])
#     return answer
#
# print(solution(["r 10", "a 23", "t 124", "k 9"]	,["PIZZA arraak 145", "HAMBURGER tkar 180", "BREAD kkk 30", "ICECREAM rar 50", "SHAVEDICE rar 45", "JUICE rra 55", "WATER a 20"],	["BREAD 5", "ICECREAM 100", "PIZZA 7", "JUICE 10", "WATER 1"]))
# # #
#########2번
# def studyTime(start,end):
#     ret=0
#     s=start.split(":")
#     e=end.split(":")
#     ret+=int(e[1])-int(s[1])+60
#     ret+=(int(e[0])-1-int(s[0]))*60
#     if(ret<5):
#         return 0
#     if(ret>=105):
#         return 105
#     return ret
# def solution(log):
#     total=0
#     for i in range(0,len(log),2):
#         start,end=log[i],log[i+1]
#         duration=studyTime(start,end)
#         total+=duration
#
#     hour=total//60
#     minute=total%60
#     s_hour="00"+str(hour)
#     s_minute="00"+str(minute)
#     answer=s_hour[-2:]+":"+s_minute[-2:]
#     return answer
# print(solution(["08:30", "09:00", "14:00", "16:00", "16:01", "16:06", "16:07", "16:11"]))
# print(solution(["01:00", "08:00", "15:00", "15:04", "23:00", "23:59"]))


######1번

# from collections import Counter
# def solution(arr):
#     answer = []
#     cnt=dict(Counter(arr))
#     maxValue=max(list(cnt.values()))
#     for i in range(1,4):
#         answer.append(maxValue-cnt.get(i,0))
#     return answer
#
# print(solution([3, 3, 3, 3, 3, 3]))