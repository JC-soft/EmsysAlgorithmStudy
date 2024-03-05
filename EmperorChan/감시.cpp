#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
using lld = long long;

//변수 선언
vector<vector<int>>dir;
vector<pair<int,int>>cctv;
int n,m,leng;
int map[8][8];
int ans = 90;
// 초기값 세팅 함수
void initialize(){
  // dir
  dir.push_back({0});
  dir.push_back({0});
  dir.push_back({0,2});
  dir.push_back({0,3});
  dir.push_back({0,2,3});
  dir.push_back({0,1,2,3});

  // input
  cin >> n >> m;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin >> map[i][j];
      if(map[i][j] && map[i][j]!=6){
        cctv.push_back({i,j});
      }
    }
  }
  leng = cctv.size();
}

void putCCTV(int num, int w, int w2, int value){
  int x = cctv[num].first , y = cctv[num].second;
  for(auto i : dir[value]){
    int nd = (i+w)%4;
    int xx = cctv[num].first;
    int yy = cctv[num].second;
    while(1){
      if(nd==0)yy++;
      else if(nd==1)xx++;
      else if(nd==2)yy--;
      else if(nd==3)xx--;
      if(xx<0 || yy<0 || xx>=n || yy>=m || map[xx][yy]==6)break; 
      if(map[xx][yy] > 0 )continue;
      map[xx][yy]+=w2;
    }
  }
}

void sol(int i){
  if(i==leng){
    // Update the ans;
    int cnt = 0;
    for(int p=0; p<n; p++){
      for(int j=0; j<m; j++){
        if(!map[p][j])cnt++;
      }
    }
    ans = min(ans,cnt);
    return;
  }
  int x = cctv[i].first , y = cctv[i].second;
  if(map[x][y]==5){
    putCCTV(i,0,-1,5);
    sol(i+1);
    putCCTV(i,0,1,5);
  }
  else{
    for(int j=0; j<4; j++){
      putCCTV(i,j,-1,map[x][y]);
      sol(i+1);
      putCCTV(i,j,1,map[x][y]);
    }
  }
}

int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  initialize();
  sol(0);  
  cout << ans;

  return 0;
}
