#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char node[22222];
vector<int> gr[22222];

char another(char virus);
void infection(int no, char virus);
bool isInfested(int no);

int main(){
    int k;
    cin >> k;
    while(k--){
        int v,e;
        cin >> v >> e;cin.ignore();
        while(e--){
            int a,b;
            cin>>a>>b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        for(int i=1; i<=v; i++){
            infection(i, another(node[i]));
        }
        for(int i=1; i<=v; i++){
            if(!isInfested(i)){
                cout<<"NO\n";
                goto supercontinue;
            }
        }
        cout<<"YES\n";
    supercontinue:
        vector<int> reset[22222];
        swap(gr,reset);
        for(int i=1; i<=v; i++){
            node[i]=0;
        }
        continue;
    }
}

char another(char virus){
    if(virus=='a') return 'b';
    return 'a';
}

void infection(int no, char virus){
    if(node[no]==virus){
        return;
    }
    else if(node[no]==another(virus)){
        return;
    }
    node[no]=virus;
    for(auto i:gr[no]){
        infection(i,another(virus));
    }
    return;
}

bool isInfested(int no){
    for(auto i:gr[no]){
        if(node[no]==node[i])
            return false;
    }
    return true;
}
