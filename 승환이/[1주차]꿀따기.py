n=int(input())
lis=list(map(int,input().split()))
per=[0] *n
per[0]=lis[0]
for i in range(1,n):
    per[i]=per[i-1]+lis[i]


res=0
ans=0

#꿀통 왼쪽 중앙 꿀벌  옮기면서

for i in range(1,n-1):
    #첫번째
    ans=0
    #맨 오른쪽 벌
    #누적합 나와 나 자신과 다른 벌 값 -
    ans=per[n-1]-lis[n-1]-lis[i]
    #누적합 i와 나 자신
    ans+=per[i]-lis[i]
    res=max(res,ans)
    
for i in range(1,n-1):
    ans=0
    #맨 왼쪽 벌
    ans=per[n-1]-lis[i]-lis[0]
    ans+=per[n-1]-per[i-1]-lis[i]
    res=max(res,ans)
    
for i in range(1,n-1):
    ans=0
    ans=per[n-1]-per[i-1]-lis[n-1]
    ans+=per[i]-lis[0]
    res=max(res,ans)
    
print(res)
