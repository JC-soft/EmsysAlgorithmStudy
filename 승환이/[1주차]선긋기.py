n =int(input())
lis=[]
for i in range(n):
    a,b=map(int,input().split())
    lis.append((a,b))
    
lis=sorted(lis)
start=lis[0][0]
end=lis[0][1]
res=0
for i in range(1,n):
    if end<=lis[i][0]:
        res+=end-start
        start=lis[i][0]
        end=lis[i][1]
    elif end<=lis[i][1] and start<=lis[i][0]:
        end=lis[i][1] 
    
       
res+=end-start
print(res)
