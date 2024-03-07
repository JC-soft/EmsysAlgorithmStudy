#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
using lld = long long;

vector<int>days;

int main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  
  int n,m,a,b, s=0;
  cin >> n >> m;
  days.resize(m+1);
  for(int i=0; i<n;i++){
    cin >> a >> b;
    s+=b;
    for(int j=m; j>=a; j--){
      days[j] = max(days[j],days[j-a]+b);
    }
  }  
  cout << s-days[m];

  return 0;
}
