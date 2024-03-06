#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, sum = 0, max;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), comp);
    max = p[0].second;
    sum += p[0].second - p[0].first;
    if(n==1){
        cout << sum;
        return 0;
    }

    for(int i = 1; i < n; i++){
        if(p[i].second <= max){
            continue;
        }

        else if(p[i].first < max){
            sum += p[i].second - max;
        }
        else{
            sum += p[i].second - p[i].first;
        }
        max = p[i].second;
    }

    cout << sum;
}
