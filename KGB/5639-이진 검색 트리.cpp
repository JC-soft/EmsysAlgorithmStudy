#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

struct node{
    int l=-1;
    int r=-1;
};

node no[1001001];
int start;

void down(int n, int now){
    if(n<now){
        if(no[now].l==-1){
            no[now].l=n;
            return;
        }
        else{
            return down(n, no[now].l);
        }
    }
    else{
        if(no[now].r==-1){
            no[now].r=n;
            return;
        }
        else{
            return down(n, no[now].r);
        }
    }
}

void 전위(int now){
    cout<<now<<'\n';
    if(no[now].l!=-1) 전위(no[now].l);
    if(no[now].r!=-1) 전위(no[now].r);
}

void 후위(int now){
    if(no[now].l!=-1) 후위(no[now].l);
    if(no[now].r!=-1) 후위(no[now].r);
    cout<<now<<'\n';
}

int main(){
    int n;
    cin>>start;
    s.push(start);
    while(cin>>n){
        down(n, start);
    }
    후위(start);
}
