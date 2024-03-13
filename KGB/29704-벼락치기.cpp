#include <iostream>
using namespace std;

int main() {
  int n, t, d, m, dp[1001]={0}, money=0;
  cin>>n>>t;
  for(int i=0; i<n; i++){
    cin>>d>>m;
    money += m;
    for(int j=t; j>=d; j--){
      dp[j] = max(dp[j], dp[j-d]+m);
    }
  }
  cout<<money-dp[t];
}
