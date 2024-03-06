#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    long double sum = 0, a, num = (long double)n;

    for(int i = n; i > 0; i--){
        sum += num/(long double)i;
    }

    cout.precision(10);
    cout << sum;
}
