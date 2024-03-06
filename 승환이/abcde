n,m=map(int,input().split())
Graph=[[] for q in range(n+1)]
visitied=[[0] for q in range(n+1)]
q=0
for _ in range(m):
    a,b= map(int,input().split())
    Graph[a].append(b)
    Graph[b].append(a)
def dfs(num,depth):
    global q
    if depth==4:
        q=1
        return
    for node in Graph[num]:
            if visitied[node]==0:
                visitied[node]=1
                dfs(node,depth+1)
                visitied[node]=0
    
for i in range(n):
    visitied= [0] *n
    visitied[i]=1
    dfs(i,0)   
print(q) 
