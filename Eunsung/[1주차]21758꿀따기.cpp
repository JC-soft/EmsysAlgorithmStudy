#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int,int>> honey(100000);
int n, maxH = 0, newH = 0;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n >> honey[0].first;
    honey[0].second = honey[0].first;
    for(int i = 1; i < n; i++){
        cin >> honey[i].first;
        honey[i].second = honey[i-1].second + honey[i].first;
    }

    for(int i = 1; i < n-1; i++){
        newH = honey[i-1].second - honey[0].second + (honey[n-1].second - honey[i].second) * 2;
        if(maxH < newH)
            maxH = newH;
        
    }

    for(int i = n-2; i>0; i--){
        newH = honey[n-2].second - honey[i].second + (honey[i-1].second * 2);
        if(maxH < newH)
            maxH = newH;
    }

    for(int i = 1; i < n-1; i++){
        newH = honey[i].second - honey[0].second + honey[n-2].second - honey[i-1].second;
        if(maxH < newH)
            maxH = newH;
    }

    cout << maxH;
}
