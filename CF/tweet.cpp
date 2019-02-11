#include<bits/stdc++.h>
using namespace std;

vector<int> ans(11,0);
vector<int> adj[11];

void dfs(int u, int p){
    for(int i:adj[u]){
        if(i!=p){
            dfs(i,u);
            ans[u]+=ans[i];
        }
    }
}

bool isprime(int x){
    if(x==1) return false;
    if(x==2)   return true;
    for(int i =2;i<=pow(x,0.5);i++){
        if(x%i==0)
            return false;
    }
    return true;
}

int main(){
    vector<int> first{6, 8, 3, 6, 4, 1, 8, 5, 1};
    vector<int> second{9, 9, 5, 7, 8, 8, 10, 8, 2};
    vector<int> arr{17, 29, 3, 20, 11, 8, 3, 23, 5, 1};

    for(int i = 0; i<9;i++){
        adj[first[i]].push_back(second[i]);
        adj[second[i]].push_back(first[i]);
    }
    for(int i=0;i<10;i++){
        if(isprime(arr[i]))
            ans[i+1]=1;
    }
    dfs(1,-1);
    for(int i=0;i<11;i++){
        cout<<ans[i]<<" ";
    }
}
