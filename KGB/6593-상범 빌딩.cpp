#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct pos{
    int x,y,z;
};

queue<pos> q;

int main(){
    int l=1,r=1,c=1;
    for(;;){
        cin>>l>>r>>c;
        if(!l && !r && !c) break;
        char 상범빌딩[33][33][33]={0};

        //빌딩내부구조입력
        for(int i=0; i<l; i++){
            for(int j=0; j<r; j++){
                for(int k=0; k<c; k++){
                    cin>>상범빌딩[i][j][k];
                    if(상범빌딩[i][j][k]=='S'){
                        q.push({i,j,k});
                    }
                }
            }
        }

        //빌딩탐험
        int move=0;
        while(!q.empty()){
            move++;
            queue<pos> tq;
            while(!q.empty()){
                pos now=q.front();
                int x=now.x, y=now.y, z=now.z;
                q.pop();
                if(x>0){
                    if(상범빌딩[x-1][y][z]=='.'){
                        상범빌딩[x-1][y][z] = '#';
                        tq.push({x-1,y,z});
                    }
                    else if(상범빌딩[x-1][y][z]=='E'){
                        queue<pos> clear;
                        swap(q,clear);
                        goto clear;
                    }
                }
                if(x<l-1){
                    if(상범빌딩[x+1][y][z]=='.'){
                        상범빌딩[x+1][y][z] = '#';
                        tq.push({x+1,y,z});
                    }
                    else if(상범빌딩[x+1][y][z]=='E'){
                        queue<pos> clear;
                        swap(q,clear);
                        goto clear;
                    }
                }
                if(y>0){
                    if(상범빌딩[x][y-1][z]=='.'){
                        상범빌딩[x][y-1][z] = '#';
                        tq.push({x,y-1,z});
                    }
                    else if(상범빌딩[x][y-1][z]=='E'){
                        queue<pos> clear;
                        swap(q,clear);
                        goto clear;
                    }
                }
                if(y<r-1){
                    if(상범빌딩[x][y+1][z]=='.'){
                        상범빌딩[x][y+1][z] = '#';
                        tq.push({x,y+1,z});
                    }
                    else if(상범빌딩[x][y+1][z]=='E'){
                        queue<pos> clear;
                        swap(q,clear);
                        goto clear;
                    }
                }
                if(z>0){
                    if(상범빌딩[x][y][z-1]=='.'){
                        상범빌딩[x][y][z-1] = '#';
                        tq.push({x,y,z-1});
                    }
                    else if(상범빌딩[x][y][z-1]=='E'){
                        queue<pos> clear;
                        swap(q,clear);
                        goto clear;
                    }
                }
                if(z<c){
                    if(상범빌딩[x][y][z+1]=='.'){
                        상범빌딩[x][y][z+1] = '#';
                        tq.push({x,y,z+1});
                    }
                    else if(상범빌딩[x][y][z+1]=='E'){
                        queue<pos> clear;
                        swap(q,clear);
                        goto clear;
                    }
                }
            }
            swap(q,tq);
        }
    fail:
        cout<<"Trapped!\n";
        goto end;
    clear:
        cout<<"Escaped in "<<move<<" minute(s).\n";
    end:
        continue;
    }
}
