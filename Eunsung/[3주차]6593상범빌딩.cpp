#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct p{
    int z;
    int y;
    int x;
};
p start, dest;
queue<p> bfsQ;
int dy[6] = {-1, 1, 0, 0, 0, 0}, dx[6] = {0, 0, -1, 1, 0, 0}, dz[6] = {0, 0, 0, 0, -1, 1}, t, l, r, c,cnt=0;
string s[30][30], tmp;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> l >> r >> c;
    while(l!=0 || r!=0 || c!=0){
        //visited,bfsQ,cnt 초기화
        bool visited[30][30][30]={0,}, clear = false, road[30][30][30] = {0,};
        bfsQ=queue<p>();
        cnt=0;
        //문자열로 입력받고 출발지 목적지 저장
        for(int j = 0; j < l; j++){
            for(int k = 0; k < r; k++){
                cin >> s[j][k];
                for(int m = 0; m < c; m++){
                    if(s[j][k][m] == '.')
                        road[j][k][m] = 1;
                    else if(s[j][k][m]=='S'){
                        start.z=j;
                        start.y=k;
                        start.x=m;
                    }
                    else if(s[j][k][m]=='E'){
                        dest.z=j;
                        dest.y=k;
                        dest.x=m;
                    }
                }
            }
        }
        visited[start.z][start.y][start.x]=true;
        bfsQ.push({start.z,start.y,start.x});
        //bfs 수행
        while(!bfsQ.empty()){
            if(clear) break;

            int qsize=bfsQ.size();
            cnt++;
            for(int j = 0; j < qsize; j++){
                if(clear) break;

                int nowz = bfsQ.front().z, nowy = bfsQ.front().y,nowx = bfsQ.front().x;
                bfsQ.pop();

                for(int k = 0; k < 6; k++){
                    int newz = nowz + dz[k], newy = nowy + dy[k], newx = nowx + dx[k];
                    //dest면 바로 종료
                    if(newz == dest.z && newy == dest.y && newx == dest.x){
                        clear = true;
                        break;
                    }
                    //아니면 탐색
                    if(newz >= 0 && newz < l && newy >= 0 && newy < r && newx >= 0 && newx < c && road[newz][newy][newx] && !visited[newz][newy][newx]){
                        visited[newz][newy][newx] = true;
                        bfsQ.push({newz, newy, newx});
                    }
                }
            }
        }


        //결과 출력
        if(clear) cout << "Escaped in "<< cnt <<" minute(s).\n";
        else cout << "Trapped!\n";

        //다음 lrc 입력
        cin >> l >> r >> c;
    }

}
