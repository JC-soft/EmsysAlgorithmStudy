#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m,n;
int p[666][666];

int ㅡ(){
    int mx=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m-3; j++){
            mx = max(mx, p[i][j]+p[i][j+1]+p[i][j+2]+p[i][j+3]);
        }
    }
    return mx;
}

int ㅣ(){
    int mx=0;
    for(int i=0; i<n-3; i++){
        for(int j=0; j<m; j++){
            mx = max(mx, p[i][j]+p[i+1][j]+p[i+2][j]+p[i+3][j]);
        }
    }
    return mx;
}

int ㅁ(){
    int mx=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i][j]+p[i][j+1]+p[i+1][j]+p[i+1][j+1]);
        }
    }
    return mx;
}

int L(){
    int mx=0;
    //■
    //■
    //■■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i][j]+p[i+1][j]+p[i+2][j]+p[i+2][j+1]);
        }
    }
    //    ■
    //■■■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i+1][j]+p[i+1][j+1]+p[i+1][j+2]+p[i][j+2]);
        }
    }

    //■■
    //  ■
    //  ■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i][j]+p[i][j+1]+p[i+1][j+1]+p[i+2][j+1]);
        }
    }

    //■■■
    //■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i][j]+p[i+1][j]+p[i][j+1]+p[i][j+2]);
        }
    }

    //  ■
    //  ■
    //■■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i+2][j]+p[i+2][j+1]+p[i+1][j+1]+p[i][j+1]);
        }
    }

    //■
    //■■■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i][j]+p[i+1][j]+p[i+1][j+1]+p[i+1][j+2]);
        }
    }

    //■■
    //■
    //■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i][j]+p[i+1][j]+p[i+2][j]+p[i][j+1]);
        }
    }

    //■■■
    //    ■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i][j]+p[i][j+1]+p[i][j+2]+p[i+1][j+2]);
        }
    }
    return mx;
}

int S(){
    int mx=0;
    //■
    //■■
    //  ■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i][j]+p[i+1][j]+p[i+1][j+1]+p[i+2][j+1]);
        }
    }

    //  ■■
    //■■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i+1][j]+p[i+1][j+1]+p[i][j+1]+p[i][j+2]);
        }
    }

    //  ■
    //■■
    //■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i][j+1]+p[i+1][j+1]+p[i+1][j]+p[i+2][j]);
        }
    }

    //■■
    //  ■■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i][j]+p[i][j+1]+p[i+1][j+1]+p[i+1][j+2]);
        }
    }
    return mx;
}

int ㅜ(){
    int mx=0;
    //■■■
    //  ■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i][j]+p[i][j+1]+p[i+1][j+1]+p[i][j+2]);
        }
    }

    //■
    //■■
    //■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i][j]+p[i+1][j]+p[i+1][j+1]+p[i+2][j]);
        }
    }

    //  ■
    //■■■
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            mx = max(mx, p[i+1][j]+p[i][j+1]+p[i+1][j+1]+p[i+1][j+2]);
        }
    }

    //  ■
    //■■
    //  ■
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            mx = max(mx, p[i+1][j]+p[i][j+1]+p[i+1][j+1]+p[i+2][j+1]);
        }
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>p[i][j];
        }
    }
    //ㅡ ㅣ ㅁ L S ㅜ
    cout<<max(ㅡ(),max(ㅣ(),max(ㅁ(),max(L(),max(S(),ㅜ())))));
    return 0;
}
