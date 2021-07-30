
from collections import deque

n,m=map(int,input().split())
graph=[]

red=[]
blue=[]
hole=[]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def move(graph,red,blue,direction):
    rcy,rcx=red
    bcy,bcx=blue
    while True:
        rny = rcy+dy[direction]
        rnx = rcx+dx[direction]
        bny=bcy+dy[direction]
        bnx=bcx+dx[direction]
        print([rny,rnx],[bny,bnx])
        if (graph[rny][rnx]=='.' and graph[bny][bnx]=='#'):
            rcy,rcx=rny,rnx
        elif (graph[rny][rnx]=='O' and graph[bny][bnx]=='#'):
            rcy,rcx=rny,rnx
            break
        elif (graph[rny][rnx]=='#' and graph[bny][bnx]=='.'):
            bcy,bcx=bny,bnx
        elif (graph[rny][rnx] == '#' and graph[bny][bnx] == 'O'):
            bcy,bcx=bny,bnx
            break
        elif (graph[rny][rnx]=='#' and graph[bny][bnx]=='#') or (graph[rny][rnx]=='#' and graph[bny][bnx]=='R') or    \
            (graph[rny][rnx] == 'B' and graph[bny][bnx] == '#'):
            break
        else:
            rcy,rcx=rny,rnx
            bcy,bcx=bny,bnx


    graph[red[0]][red[1]]='.'
    graph[blue[0]][blue[1]]='.'
    graph[rcy][rcx]='R'
    graph[bcy][bcx]='B'

    return [rcy,rcx],[bcy,bcx]

def dfs(graph,red,blue,hole):

    stack=deque()
    #갈 방향 선택
    for i in range(4):
        stack.append((i,0))
    while stack:
        direction,count=stack.pop()
        print(direction,count)
        n_red,n_blue= move(graph,red,blue,direction)
        printf(graph)
        if n_red[0]==hole[0] and n_red[1]==hole[1]:
            return count
        elif n_blue[0]==hole[0] and n_blue[1]==hole[1]:
            return -1
        for i in range(4):
            if abs(i-direction)==2 or i==direction :
                continue
            stack.append((i,count+1))

    return -1
for i in range(n):
    row=input()
    red_col=row.find('R')
    blue_col=row.find('B')
    hole_col=row.find('O')
    if red_col!=-1:
        red.extend([i,red_col])
    if blue_col!=-1:
        blue.extend([i,blue_col])
    if hole_col!=-1:
        hole.extend([i,hole_col])
    graph.append(list(row))

def printf(graph):
    for i in range(n):
        for j in range(m):
            print(graph[i][j],end='')
        print()


dfs(graph,red,blue,hole)