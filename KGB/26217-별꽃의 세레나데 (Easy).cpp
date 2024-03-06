#include <iostream>
using namespace std;
int main() {
  double d = 0;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    d+=(double)n/i;
  }
  cout<<d;
}
