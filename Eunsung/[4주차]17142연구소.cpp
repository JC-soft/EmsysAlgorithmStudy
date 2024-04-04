#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<vector<int>>map(50,vector<int>(50,0));
vector<vector<bool>>chk(50,vector<bool>(50,0));
vector<bool>exist(10,0);
vector<pair<int,int>> virus;
queue<pair<int,int>> bfsQ;
int n,m,vsize=0,dy[4]={-1,1,0,0},dx[4]={0,0,-1,1},cnt,space,tmpspace,mincnt=1000000;


    //logic
    /*
    빈공간의 수를 space변수에 저장.
    vsize C m 개의 경우의 수 모두에 대하여... : 재귀함수. depth가 m이 될 때까지 재귀하며 bfs호출
    ->각 경우의 수마다 조합되는 바이러스칸들을 bfsQ에 넣고 bfs를 수행한다
    ->bfs수행 전에 방문배열, tmpspace 모두 초기화. 
    ->bfs가 종료될 경우 tmpspace==0이면 min과 비교해 min을 갱신한다.
    ->tmpspace!=0이면 그대로 continue
    ->모든 경우의 수에 대해 bfs를 수행하고 나서 min이 한 번도 갱신되지 않았으면 -1출력
    */

void bfs(){
    cnt=-1;
    tmpspace=space;
    while(!bfsQ.empty()){
        if(tmpspace<=0 && map[bfsQ.front().first][bfsQ.front().second] == 2){
            bfsQ.pop();
            continue;
        }
        int qsize = bfsQ.size();
        cnt++;
        for(int i = 0; i < qsize; i++){
            int y = bfsQ.front().first, x = bfsQ.front().second, ny,nx;
            bfsQ.pop();
            for(int j = 0; j < 4; j++){
                ny=y+dy[j];
                nx=x+dx[j];
                if(ny>=0 && ny<n && nx>=0 && nx<n && !chk[ny][nx] && map[ny][nx]!=1){
                    if(map[ny][nx]==0)tmpspace--;
                    
                    chk[ny][nx]=1;
                    bfsQ.push({ny,nx});
                }
            }
        }
    }

    if(tmpspace<=0 && cnt < mincnt){
        mincnt = cnt;
    }
}


void comb(int now, int depth){

    if(depth<m){//재귀
        for(int i = now+1; i < vsize; i++){
            exist[i]=true;
            comb(i, depth+1);
            exist[i]=false;
        }
    }
    else{
        chk = vector<vector<bool>>(50,vector<bool>(50,0));
        for(int i = 0; i < vsize; i++){
            if(exist[i]){

                chk[virus[i].first][virus[i].second]=true;
                bfsQ.push({virus[i].first, virus[i].second});
            }
        }

        bfs();
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n>>m;
    space=n*n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j]==2){
                virus.push_back({i,j});
                vsize++;
            }
            if(map[i][j]!=0){
                space--;
            }
        }
    }

    comb(-1,0);

    if(mincnt==1000000) cout << -1;
    else if(mincnt == -1) cout << 0;
    else cout << mincnt;
}
