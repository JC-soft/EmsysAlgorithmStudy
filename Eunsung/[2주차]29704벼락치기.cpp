#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, t, day, price, sum = 0;
    cin >> n >> t;
    vector<int> dp(t+1, 0);
    for(int i = 0; i < n; i++){
        cin >> day >> price;
        sum+=price;
        for(int j = t; j >= day; j--){
            dp[j] = max(dp[j], dp[j-day] + price);
        }
    }
    cout << sum - dp[t];
}
