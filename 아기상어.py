import math
import sys
from heapq import *
from collections import deque
from itertools import combinations

n=int(input())
sx=0
sy=0
q=[]
Map=[list(map(int,input().split()))for _ in range(n)]

for i in range(n):
    for j in range(n):
        if Map[i][j]==9:
            sx=i
            sy=j
            Map[i][j]=0
            heappush(q,(0,i,j))


def bfs():
    size,size_cnt= 2, 0
    global Recnt_res
    Recnt_res=0
    #북 서   동 남
    dx=[-1,0,0,1]
    dy=[0,-1,1,0]
    visitieid = [[0] * (n) for _ in range(n)]
    visitieid[sx][sy]=1
    while q:
        d,x,y=heappop(q)
        if Map[x][y]>0 and Map[x][y]<size:
            size_cnt += 1
            Map[x][y] = 0
            visitieid = [[0] * (n) for _ in range(n)]
            q.clear()
            Recnt_res += d
            d= 0
            if size_cnt == size:
                size = size + 1
                size_cnt = 0
            heappush(q, (d, x, y))
        for i in range(4):
            nx=dx[i]+x
            ny=dy[i]+y
            nd=d+1
            if nx>=0 and ny>=0 and nx<n and ny<n:
                if visitieid[nx][ny]==0 and Map[nx][ny]<=size:
                    visitieid[nx][ny]=1
                    heappush(q,(nd,nx,ny))


bfs()
print(Recnt_res)
