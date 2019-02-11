#include<bits/stdc++.h>
using namespace std;

bool check(int i, int j, int n){
    if(i>=n || i<0 || j>=n || j<0)
        return false;
    return true;
}

int get(int i, int j, int n){
    int te =0;
    te += i*n;
    te += j;
    return te;
}
void make(int ar[][4], vector<int> adj[]){
    for(int i = 0;i<4; i++){
        for(int j =0;j<4;j++){
            if(!ar[i][j])
                continue;
            if(check(i-1,j,4) && ar[i-1][j])
                adj[get(i,j,4)].push_back(get(i-1,j,4));
            if(check(i,j-1,4) && ar[i][j-1])
                adj[get(i,j,4)].push_back(get(i,j-1,4));
            if(check(i+1,j,4) && ar[i+1][j])
                adj[get(i,j,4)].push_back(get(i+1,j,4));
            if(check(i,j+1,4) && ar[i][j+1])
                adj[get(i,j,4)].push_back(get(i,j+1,4));
        }
    }
}

string str = "";
string str2 = "";

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited, int id)
{
    visited[u] = true;
    //cout << u << " ";
    string te = to_string(u);
    if(id == 1) str.append(te);
    else    str2.append(te);

    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false){
            if(id == 1) DFSUtil(adj[u][i], adj, visited, 1);
            else DFSUtil(adj[u][i], adj, visited, 2);
        }
}

// void DFS(vector<int> adj[], int V)
// {
//
//     for (int u=0; u<V; u++)
//         if (visited[u] == false)
//             DFSUtil(u, adj, visited);
// }

int main(){
    int n = 4;
    int ar[4][4] = {
        {1,1,1,0},
        {0,1,1,1},
        {0,0,0,1},
        {0,0,1,1},
    };

    int ar2[4][4] = {
        {1,0,1,0},
        {0,1,1,1},
        {0,0,0,1},
        {0,0,1,1},
    };
    vector<bool> visited(16, false);
    vector<bool> visited2(16, false);
    vector<int> adj[16];
    vector<int> adj2[16];

    make(ar, adj);
    make(ar2,adj2);

    int ans = 0;

    for (int u=0; u<16; u++){
        int x = 0, y =0;
        if (visited[u] == false && ar[u/4][u%4]){
            DFSUtil(u, adj, visited, 1); x=1;
        }
        if (visited2[u] == false && ar2[u/4][u%4]){
            DFSUtil(u, adj2, visited2, 2); y=1;
        }

        //cout<<endl<<str<<" "<<str2<<endl;
        if(x==1 && y==1 && str == str2) ans++;
        str = "";
        str2 = "";
    }
    cout<<ans;
}
