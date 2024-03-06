#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<int> graph[2000];
vector<bool> visited(2000, 0);
int n, m, a, b, cnt = 0;
void dfs(int now){
    if(cnt == 4){
        return;
    }
    int size = graph[now].size();
    for(int i = 0; i < size; i++){
        if(cnt == 4)
            return;
        int next = graph[now][i];
        if(!visited[next]){
            visited[next] = true;
            cnt++;
            dfs(next);
        }
    }
    if(cnt == 4)
        return;
    cnt--;
    visited[now] = false;
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    for(int i = 0; i < n; i++){
        visited = vector<bool>(2000, 0);
        visited[i] = true;
        cnt = 0;
        dfs(i);
        if(cnt == 4)
            break;
    }

    if(cnt == 4)
        cout << 1;
    else
        cout << 0;
}
