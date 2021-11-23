# def main():
#     x =list(input())
#     attack=[i for i in x if i=='(']
#     depend=[i for i in x if i==')']
#     if len(attack)==len(depend):
#         print("YES")
#     else:
#         print("NO")
#
#
# if __name__=="__main__":
#     main()

###########################level2 ...programers####################
# import math
# import sys
# from itertools import permutations
#
# def eratos(array):
#     length=len(array)
#     array[0]=False
#     array[1]=False
#     for i in range(2,int(math.sqrt(length))+1):
#         j=2
#         while i*j<length:
#             array[i*j]=False
#             j+=1
#
# def solution(numbers):
#     numbers=list(numbers)
#     length=len(numbers)
#     isPrime=[True]*(pow(10,length))
#     eratos(isPrime)
#     result = set([])
#
#     for i in range(1,length+1):
#         for j in list(permutations(numbers,i)):
#             if j[0]==0: continue
#             temp=int("".join(j))
#             if isPrime[temp]==True:
#                 result.add(temp)
#
#     return len(result)

#################################2번#############################
# def append(id,lang,field,career,fav):
#     global cpp,java,python,back,front,jun,sen,chicken,pizza
#     if lang == "cpp":
#         cpp.add(id)
#     elif lang == "java":
#         java.add(id)
#     elif lang == "python":
#             python.add(id)
#
#     if field == "back":
#         back.add(id)
#     elif field == "front":
#         front.add(id)
#
#     if career == "jun":
#         jun.add(id)
#     elif career == "sen":
#         sen.add(id)
#
#     if fav == "chicken":
#         chicken.add(id)
#     elif field == "pizza":
#         pizza.add(id)
#
# def solution(info, query):
#     length=len(info)
#     cpp,java,python=set([]),set([]),set([])
#     back,front=set([]),set([])
#     jun,sen=set([]),set([])
#     chicken,pizza=set([]),set([])
#     scores=[0]*(length+1)
#     for i in range(length):
#         lang,field,career,fav,score=info[i].split()
#         append(i,lang,field,career,fav)
#         scores[i]=score
#
#     for i in query:
#         lang,field,career,remainder=info[i].split(" and ")
#         fav,score=remainder.split()
#     answer = []
#     return answer
# solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],
#          ["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"])
# import math
# from itertools import permutations
# def eratos(array):
#     length=len(array)
#     array[0]=False
#     array[1]=False
#     for i in range(2,int(math.sqrt(length))+1):
#         j=2
#         while i*j<length:
#             array[i*j]=False
#             j+=1
#
#
# def solution(numbers):
#     numbers=list(map(int,list(numbers)))
#     answer = 0
#     length=len(numbers)
#     array=[True]*int(math.pow(10,length))
#     eratos(array)
#     for i in range(1,length+1):
#         for case in list(permutations(numbers,i)):
#             num = int("".join(map(str, case)))
#             # print(num)
#             if array[num] == True:
#                 print(num)
#                 answer += 1
#     return answer
# # print(list(map(int,list("157"))))
# print(solution("011"))