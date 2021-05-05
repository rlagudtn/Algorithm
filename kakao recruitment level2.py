# #####################경주로 건설
# from collections import deque
# import time
#
# def solution(board):
#     def bfs(start):
#         dy = [-1, 0, 1, 0]
#         dx = [0, 1, 0, -1]
#         n = len(board)
#         cost_board = [[int(1e9)] * n for _ in range(n)]
#         q = deque([start])
#         cost_board[0][0]=0
#
#         while q:
#             y,x,cost,dir=q.popleft()
#             for i in range(len(dy)):
#                 ny=y+dy[i]
#                 nx=x+dx[i]
#                 n_cost=cost+600 if i!=dir else cost+100
#                 if 0<=ny<n and 0<=nx<n and board[ny][nx]==0 and cost_board[ny][nx]>n_cost:
#                     q.append((ny,nx,n_cost,i))
#                     cost_board[ny][nx]=n_cost
#         return cost_board[-1][-1]
#
#         return
#     return min(bfs((0,0,0,1)),bfs((0,0,0,2)))
# print(solution([[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]))



# # ################불량 사용자
# from itertools import permutations
# # lst=[[1,2,3],['a','b'],[10,11]]
# # print(list(product(*lst))) #########곱집합 이차원배열
# # a=set((1,2,3))
# # print(len(a))
# def matched(user,banned):
#     length=len(banned)
#     if len(user)!=length:
#         return False
#     for i in range(length):
#         if banned[i]=='*':
#             continue
#         elif banned[i]!=user[i]:
#             return False
#
#     return True
# def overlaped(arr,el):
#     temp_el = set(el)
#     for i in arr:
#         temp=set(i)
#         if temp==temp_el:
#             return True
#     return False
# def solution(user_id, banned_id):
#     answer = []
#     for i in list(permutations(user_id,len(banned_id))):
#         temp=[]
#         for j in range(len(banned_id)):
#             if not matched(i[j],banned_id[j]):
#                 break
#             temp.append(i[j])
#         if len(temp)==len(banned_id) and not overlaped(answer,temp):
#             answer.append(temp)
#     return len(answer)
#
# print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"],
#                ["fr*d*", "*rodo", "******", "******"]))








###################보석 쇼

#
# def solution(gems):
#     kind_of_gems=len(set(gems))
#     size=len(gems)
#     answer=[0,size-1]
#     min=size;
#     dic={gems[0]:1}
#     start=end=0
#     while(start<size and end<size):
#         if len(dic)==kind_of_gems:
#             if min>end-start+1:
#                 answer=[start,end]
#                 min=end-start+1
#
#             if(dic[gems[start]]==1):
#                 del dic[gems[start]]
#             elif(dic[gems[start]]>1):
#                 dic[gems[start]]-=1
#             start+=1
#         else:
#             end+=1
#             if end>=size:
#                 break
#             if(gems[end] in dic.keys()):
#                 dic[gems[end]]+=1
#             else:
#                 dic[gems[end]]=1
#
#
#     ret_s,ret_e=answer
#     return [ret_s+1,ret_e+1]
#
# print(solution(["ZZZ", "YYY", "NNNN", "YYY", "BBB"]))

# #####################수식 최대화
# from itertools import permutations
#
# def seperate(expression):
#     nums=[]
#     symbols=[]
#     kind_of_symbols=set([])
#     temp=''
#     for i in expression:
#         if not i.isdigit():
#             symbols.append(i)
#             kind_of_symbols.add(i)
#             nums.append(temp)
#             temp=''
#             continue
#         temp+=i
#     nums.append(temp)
#     return nums,symbols,kind_of_symbols
#
#
# def calculate(nums,symbols,priority_syms):
#     temp_nums=nums[:]
#     temp_syms=symbols[:]
#     for i in priority_syms:
#         j=0;
#         while(j<len(temp_syms)):
#             if(temp_syms[j]==i):
#                 temp=eval(temp_nums[j]+temp_syms[j]+temp_nums[j+1])
#                 temp_nums[j]=str(temp)
#                 temp_nums.pop(j+1)
#                 temp_syms.pop(j)
#             else:
#                 j+=1
#     print(temp_nums)
#     print(temp_syms)
#     return abs(int(temp_nums[0]))
#
#
#
# def solution(expression):
#     answer = 0
#     nums,symbols,kind_of_symbols=seperate(expression)
#     for i in permutations(kind_of_symbols,len(kind_of_symbols)):
#         value=calculate(nums,symbols,i)
#         answer=max(answer,value)
#     return answer

# print(solution("50*6-3*2"))


# #################메뉴 리뉴얼
# from collections import Counter
# from itertools import combinations
# def get_max_course(lst):
#     ret=[]
#     if len(lst)==0:
#         return ret
#     if lst[0][1]<=1:
#         return ret
#     ret=[lst[0][0]]
#     max_value=lst[0][1]
#     for i in range(1,len(lst)):
#         if lst[i][1]<max_value:
#             break
#         ret.append(lst[i][0])
#     return ret
# def get_combi(course,order):
#     combi_arr=[]
#     for i in course:
#         lst=[]
#         for j in combinations(i,order):
#             temp=list(j)
#             temp.sort()
#             lst.append(''.join(temp))
#         combi_arr.append(Counter(lst))
#     temp=combi_arr[0]
#     for i in range(1,len(combi_arr)):
#         temp=temp+combi_arr[i]
#
#     lst=list(temp.items())
#     lst.sort(key=lambda x:x[1],reverse=True)
#     return get_max_course(lst)
# def solution(orders, course):
#     answer = []
#     for i in course:
#         answer+=(get_combi(orders,i))
#     answer.sort()
#     return answer
#
# print(solution(["XYZ", "XWY", "WXA"],[2,3,4]))

# ###################튜플
# def make_list(s):
#     ret=[]
#     temp = []
#     num=""
#     isIn=False
#     for i in s[1:-1]:
#
#         if i=='{':
#             isIn=True
#
#         elif i == "}":
#             temp.append(int(num))
#             num = ""
#             ret.append(set(temp))
#             temp=[]
#             isIn=False
#         elif i=="," and isIn==True:
#             temp.append(int(num))
#             num=""
#         elif i.isdigit():
#             num+=i
#
#
#     return ret
#
#
# def solution(s):
#     answer = []
#
#     set_arr=make_list(s)
#     set_arr.sort(key=lambda x:len(x))
#     answer.append(list(set_arr[0])[0])
#     for i in range(0,len(set_arr)-1):
#         addedElement=set_arr[i+1]-set_arr[i]
#         answer.append(list(addedElement)[0])
#
#     return answer


# ################## 뉴스 클러스터링
# import math
# from collections import Counter
# def two_char(s):
#     ret=[]
#     for i in range(0,len(s)-1):
#         if s[i].isalpha() and s[i+1].isalpha():
#             ret.append(s[i]+s[i+1])
#     return ret
#
# def solution(str1, str2):
#     str1=str1.upper()
#     str2=str2.upper()
#
#     two_chars1=two_char(str1)
#     two_chars2=two_char(str2)
#
#     set1=Counter(two_chars1)
#     set2=Counter(two_chars2)
#     print(set1)
#     print(set2)
#     union=(set1|set2).values()
#     interSec=(set1&set2).values()
#
#     answer=1
#     if len(union)!=0:
#         answer=sum(interSec)/sum(union)
#
#     return math.trunc(answer*65536)
#
#
# print(solution('france','french'))
# print(solution('aa1+aa2','AAAA12'))
# print(solution('E=M*C^2','e=m*c^2'))
#
#

# #################괄호 변환
# def isCorrect(p):
#     left=0
#     right=0
#     for i in p:
#         if i=='(':
#             left+=1
#         else: right+=1
#         if left<right:
#             return False
#
#     return True
#
# def pivot_UV(p):
#     i=0
#     left=right=0
#     while i==0 or left!=right:
#         if p[i]=='(':left+=1
#         else: right+=1
#         i+=1
#     return i
#
# def reverseBraket(p):
#     answer=''
#     for i in p:
#         if i=='(':answer+=')'
#         else: answer+='('
#
#     return answer
#
#
#
# def solution(p):
#     answer = ''
#     if len(p)==0: return ''
#
#     index = pivot_UV(p)
#     u=p[:index]
#     v=p[index:]
#
#     if isCorrect(u):
#         answer=u+solution(v)
#     else:
#         temp='('
#         temp+=solution(v)
#         temp+=')'
#         temp+=reverseBraket(u[1:-1])
#         return temp
#     return answer





# def getCount(s,temp,start):
#     count=0
#     length=len(temp)
#     for k in range(start,len(s),length):
#         if k+length>len(s):
#             break
#         if s[k:k+length]==temp:
#             count+=1
#         else: break
#     return count
#
# def solution(s):
#     answer = len(s)
#     size=len(s)
#     #1. 문자열 길이의 절반만큼 반복 // 길이: i
#     for i in range(1,size//2+1):
#         string=""
#         #1.1 문자열 순회(j)
#         j=0
#         while(j<size):
#             temp=s[j:j+i]
#             #1.1.1. 뒤에 연속한 단어의 개수를 찾는다.
#             count=getCount(s,temp,j)
#             #1.1.2 개수가 1개라면 j를 1 증가시킨다
#             if count==1:
#                 j+=i
#
#             #1.1.3. 개수가 다수라면 j+=count*i
#             else:
#                 j+=count*i
#                 string+=str(count)
#             string+=temp
#         #최소 문자열로 갱신한다.
#         answer=min(answer,len(string))
#     return answer
# print(solution("aabbaccc"))
# print(solution("ababcdcdababcdcd"))
# print(solution("abcabcdede"))
# print(solution("abcabcabcabcdededededede"))
# print(solution("xababcdcdababcdcd"))
