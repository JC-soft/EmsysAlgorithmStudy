#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a[999][999];

void left (int x, int y);
void right(int x, int y);
void up   (int x, int y);
void down (int x, int y);

void printAllSand(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<a[i+10][j+10]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    int startSand=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i+10][j+10];
            startSand+=a[i+10][j+10];
        }
    }

    int shkx=n/2+10, shky=n/2+10;
    for(int i=1; i<n; i++){
        if(i%2){
            for(int j=0; j<i; j++){
                shkx--;
                left(shkx,shky);
            }
            for(int j=0; j<i; j++){
                shky++;
                down(shkx,shky);
            }
        }
        else{
            for(int j=0; j<i; j++){
                shkx++;
                right(shkx,shky);
            }
            for(int j=0; j<i; j++){
                shky--;
                up(shkx,shky);
            }
        }
    }
    for(int i=1; i<n; i++){
        shkx--;
        left(shkx,shky);
    }

    int innerSand=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            innerSand += a[i+10][j+10];
            // cout<<a[i+10][j+10]<<' ';
        }
        // cout<<'\n';
    }
    cout<<startSand-innerSand;
    return 0;
}

void left(int x, int y){
    int sand=0, now;

    now = int(a[y][x]*0.02);
    a[y-2][x] += now;
    a[y+2][x] += now;
    sand += now*2;

    now = int(a[y][x]*0.07);
    a[y-1][x] += now;
    a[y+1][x] += now;
    sand += now*2;

    now = int(a[y][x]*0.1);
    a[y-1][x-1] += now;
    a[y+1][x-1] += now;
    sand += now*2;

    now = int(a[y][x]*0.01);
    a[y-1][x+1] += now;
    a[y+1][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.05);
    a[y][x-2] += now;
    sand += now;

    a[y][x-1] += a[y][x]-sand;
    a[y][x] = 0;
}

void right(int x, int y){
    int sand=0, now;

    now = int(a[y][x]*0.02);
    a[y-2][x] += now;
    a[y+2][x] += now;
    sand += now*2;

    now = int(a[y][x]*0.07);
    a[y-1][x] += now;
    a[y+1][x] += now;
    sand += now*2;

    now = int(a[y][x]*0.1);
    a[y-1][x+1] += now;
    a[y+1][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.01);
    a[y-1][x-1] += now;
    a[y+1][x-1] += now;
    sand += now*2;

    now = int(a[y][x]*0.05);
    a[y][x+2] += now;
    sand += now;

    a[y][x+1] += a[y][x]-sand;
    a[y][x] = 0;
}

void up(int x, int y){
    int sand=0, now;

    now = int(a[y][x]*0.02);
    a[y][x-2] += now;
    a[y][x+2] += now;
    sand += now*2;

    now = int(a[y][x]*0.07);
    a[y][x-1] += now;
    a[y][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.1);
    a[y-1][x-1] += now;
    a[y-1][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.01);
    a[y+1][x-1] += now;
    a[y+1][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.05);
    a[y-2][x] += now;
    sand += now;

    a[y-1][x] += a[y][x]-sand;
    a[y][x] = 0;
}

void down(int x, int y){
    int sand=0, now;

    now = int(a[y][x]*0.02);
    a[y][x-2] += now;
    a[y][x+2] += now;
    sand += now*2;

    now = int(a[y][x]*0.07);
    a[y][x-1] += now;
    a[y][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.1);
    a[y+1][x-1] += now;
    a[y+1][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.01);
    a[y-1][x-1] += now;
    a[y-1][x+1] += now;
    sand += now*2;

    now = int(a[y][x]*0.05);
    a[y+2][x] += now;
    sand += now;

    a[y+1][x] += a[y][x]-sand;
    a[y][x] = 0;
}
