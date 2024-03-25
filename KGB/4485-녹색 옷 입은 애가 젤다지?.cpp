#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct rupee{
    int x;
    int y;
    int value;
};

int cave[666][666], dijk[666][666];
bool comp[666][666];

void init(int);
void input(int);
int solve(int);
rupee dijkstra(int);

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, pnum=0;
    while(cin>>n){
        if(n==0) break;
        pnum++;
        init(n);
        input(n);
        cout<<"Problem "<<pnum<<": "<<solve(n)<<'\n';
    }
    return 0;
}

void init(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dijk[i][j] = 2147483647;
            comp[i][j] = false;
        }
    }
}

void input(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cave[i][j];
        }
    }
    dijk[0][0] = cave[0][0];
}

int solve(int n){
    rupee rp;
    do{
        rp=dijkstra(n);
        if(rp.x>0 && !comp[rp.y][rp.x-1]){
            dijk[rp.y][rp.x-1] = min(dijk[rp.y][rp.x-1], rp.value+cave[rp.y][rp.x-1]);
        }
        if(rp.x<n-1 && !comp[rp.y][rp.x+1]){
            dijk[rp.y][rp.x+1] = min(dijk[rp.y][rp.x+1], rp.value+cave[rp.y][rp.x+1]);
        }
        if(rp.y>0 && !comp[rp.y-1][rp.x]){
            dijk[rp.y-1][rp.x] = min(dijk[rp.y-1][rp.x], rp.value+cave[rp.y-1][rp.x]);
        }
        if(rp.y<n-1 && !comp[rp.y+1][rp.x]){
            dijk[rp.y+1][rp.x] = min(dijk[rp.y+1][rp.x], rp.value+cave[rp.y+1][rp.x]);
        }
    }while(rp.x!=n-1 || rp.y!=n-1);

    // cout<<'\n';
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<(dijk[i][j]==2147483647?-1:dijk[i][j])<<' ';
    //     }
    //     cout<<'\n';
    // }

    return rp.value;
}

rupee dijkstra(int n){
    rupee minn={-1,-1,2147483647};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!comp[i][j] && dijk[i][j]<minn.value){
                minn={j,i,dijk[i][j]};
            }
        }
    }
    comp[minn.y][minn.x] = true;
    return minn;
}
