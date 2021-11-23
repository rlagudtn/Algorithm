# ###################3190 뱀
#
# import sys
# input=sys.stdin.readline
#
# n=int(input())
# k=int(input())
# arr=[[0]*(n+1) for _ in range(n+1)]
#
# apples=[[0]*(n+1) for _ in range(n+1)]
# changeDir=[[0]*(n+1) for _ in range(n+1)]
# for _ in range(k):
#     y,x=map(int,input().split())
#     apples[y][x]=1
# l=int(input())
# dirArr=[0]*10001
# for _ in range(l):
#     s,d=input().split()
#     dirArr[int(s)]=d
#
# arr[1][1]=1
# sec=0
#
# #상:0, 우:1, 하:2, 왼:3
# dy=[-1,0,1,0]
# dx=[0,1,0,-1]
#
#
# hy,hx=1,1
# ty,tx=1,1
#
# dirs=[1]
# def getDir(dir):
#     headDir=dirs[0]
#     nDir=0
#     if dir=="D":
#         nDir=headDir+1
#     elif dir=="L":
#         nDir=headDir-1
#
#     nDir=nDir%4
#     return nDir
#
#
# while 1:
#     sec+=1
#
#     #머리를 이동시킨다
#     headDir = dirs[0]
#     hy += dy[headDir]
#     hx += dx[headDir]
#     if hy < 1 or hy > n or hx < 1 or hx > n or arr[hy][hx] == 1:
#         break
#     arr[hy][hx] = 1
#     #사과가 있다면 사과 없애고 꼬리 움직x
#     tailDir=dirs[-1]
#     if apples[hy][hx] == 0:
#         arr[ty][tx] = 0
#         ty += dy[tailDir]
#         tx += dx[tailDir]
#     else:
#         apples[hy][hx]=0
#
#     if dirArr[sec]!=0:
#         dirs.insert(0,getDir(dirArr[sec]))
#         changeDir[hy][hx]=1
#
#     if changeDir[ty][tx]==1:
#         dirs.pop(-1)
#
# print(sec)
