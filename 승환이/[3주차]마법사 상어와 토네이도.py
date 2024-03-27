import math
import sys
from heapq import *
from collections import deque
from itertools import combinations


def tonado(nx,ny,d):
    global res
    #0 0 넘어서 0 -1까지 들어옴 현재
    if ny<0:
        return
    #좌
    ####print(res)
    val=0
    if d==0:
        for x,y, z in left_sand:
            now_x=x+nx
            now_y=y+ny
            # 모래 뿌려주는 자리 맨 마지막에 val 만큼 값이 빠져야함
            if z==0:
                sand=arr[nx][ny]-val
            #빠져나가는 비율 갱신
            else:
                sand =int(z*arr[nx][ny])
                val+=sand
            #결국 나중에는 알파 자리에 온 곳에서 빠진 총 값 넣어줌
            if now_x>=0 and now_y>=0 and now_x<n and now_y<n:
                arr[now_x][now_y]+=sand
            else:
                res+=sand
    #하
    elif d==1:
        for x,y, z in down_sand:
            now_x=x+nx
            now_y=y+ny
            # 모래 뿌려주는 자리 맨 마지막에 val 만큼 값이 빠져야함
            if z==0:
                sand=arr[nx][ny]-val
            #비율 갱신
            else:
                sand = int(z * arr[nx][ny])
                val+=sand

            if now_x>=0 and now_y>=0 and now_x<n and now_y<n:
                arr[now_x][now_y]+=sand
            else:
                res+=sand
    #우
    elif d==2:
        for x,y, z in right_sand:
            now_x=x+nx
            now_y=y+ny
            # 모래 뿌려주는 자리 맨 마지막에 val 만큼 값이 빠져야함
            if z==0:
                sand=arr[nx][ny]-val
            #비율 갱신
            else:
                sand = int(z * arr[nx][ny])
                val+=sand

            if now_x>=0 and now_y>=0 and now_x<n and now_y<n:
                arr[now_x][now_y]+=sand
            else:
                res+=sand
    #상
    else:
        for x,y, z in up_sand:
            now_x=x+nx
            now_y=y+ny
            # 모래 뿌려주는 자리 맨 마지막에 val 만큼 값이 빠져야함
            if z==0:
                sand=arr[nx][ny]-val
            #비율 갱신
            else:
                sand = int(z * arr[nx][ny])
                val+=sand

            if now_x>=0 and now_y>=0 and now_x<n and now_y<n:
                arr[now_x][now_y]+=sand
            else:
                res+=sand
    ####  print(nx,ny)
        #### for x in range(n):
            ####     for y in range(n):
        ####        print(arr[x][y], end=" ")
    ####       print("")

n=int(input())
arr=[list(map(int,input().split())) for _ in range(n)]

start_x=int(n/2)
start_y=int(n/2)
res=0
#좌 하 우 상
dx=[0,1,0,-1]
dy=[-1,0,1,0]
#모래 좌표
#마지막은 비율
#마지막은  가야하는 a좌표
left_sand=[(1,1,0.01),(-1,1,0.01),(1,0,0.07),(-1,0,0.07),(-1,-1,0.1),
           (1,-1,0.1),(0,-2,0.05),(-2,0,0.02),(2,0,0.02),(0,-1,0)]
right_sand=[(x,-y,z) for x,y,z in left_sand]
down_sand=[(-y,-x,z) for x,y,z in left_sand]
up_sand=[(y,x,z) for x,y,z in left_sand]
t=0
#5면 25번 돌아야하니까
#-1 안해주면 한  방향 사이클 더 들어감
#복잡하게 visitied배열,경계검색 이런거 안해도됨
for i in range(2*n-1):
    d=i%4
    #좌1,하1,우2,상2,좌3,하3, 좌하,우상 세트로 늘어남
    if d==0 or d==2:
        t+=1
    for _ in range(t):
        nx=start_x+dx[d]
        ny= start_y+dy[d]
        tonado(nx,ny,d)
        start_x=nx
        start_y=ny
        #print(nx,ny)

####for x in range(n):
    #for y in range(n):
    #    print(arr[x][y],end=" ")
    #print("")
print(res)
