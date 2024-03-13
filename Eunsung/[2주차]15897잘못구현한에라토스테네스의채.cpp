#include<iostream>
#include<math.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long sum = 0;
    int n, i, j, mid;

    cin >> n;
    n--;

    mid = sqrt(n);
    for(i = 1; i <= mid; i++){
        sum += (n/i);
    }
    
    for(i = mid+1; i <= n; i = j+1){
        j = n/(n/i);
        sum += (n/i)*(j-i+1);
    }
    sum += n+1;

    cout << sum;
}
