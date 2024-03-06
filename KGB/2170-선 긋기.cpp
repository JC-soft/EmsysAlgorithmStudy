#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> pv, pv2;

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        pv.push_back(make_pair(a,b));
    }
    sort(pv.begin(),pv.end());
    for(int i=0; i<n-1; i++){
        if(pv[i].first!=pv[i+1].first){
            pv2.push_back(pv[i]);
        }
    }
    pv2.push_back(pv[n-1]);
    vector<pair<int,int>> asdf;
    swap(asdf,pv);
    pv.push_back(pv2[0]);
    int count=0;
    n = pv2.size();
    for(int i=0; i<n; i++){
        if(pv[count].second<pv2[i].first){
            pv.push_back(pv2[i]);
            count++;
        }
        else{
            pv[count].second = max(pv2[i].second, pv[count].second);
        }
    }
    int len=0;
    for(auto i:pv){
        //cout<<i.first<<" "<<i.second<<endl;
        len+=i.second-i.first;
    }
    cout<<len;
}
