// A simple representation of graph using STL,
// for the purpose of competitive programming
#include<bits/stdc++.h>
using namespace std;

int ans,temp,te2;
// A utility function to add an edge in an
// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to do DFS of graph
// recursively from a given vertex u.
void DFSUtil(int u, vector<int> adj[],
					vector<bool> &visited, int &temp, int &te2)
{
	visited[u] = true;
	temp++;
	//cout<<temp<<"here";
	te2 += adj[u].size();
	//cout << u << " ";
	for (int i=0; i<adj[u].size(); i++)
		if (visited[adj[u][i]] == false)
			DFSUtil(adj[u][i], adj, visited, temp, te2);
}

// This function does DFSUtil() for all
// unvisited vertices.
void DFS(vector<int> adj[], int V)
{
	vector<bool> visited(V, false);

	for (int u=0; u<V; u++){
		temp=0,te2=0;
		if (visited[u] == false){
			DFSUtil(u, adj, visited, temp, te2);
		    //cout<<temp<<" "<<te2<<endl;
		    if(temp*2 == te2)
		        ans++;
		}
	}
}

// Driver code
int main()
{
	int n,m;
	cin>>n>>m;
    ans = 0;
	// The below line may not work on all
	// compilers. If it does not work on
	// your compiler, please replace it with
	// following
	// vector<int> *adj = new vector<int>[V];
	vector<int> adj[n];
	for(int i =0; i<m; i++){
	    int x,y;
	    cin>>x>>y;
	    addEdge(adj, x-1, y-1);
	}

	// Vertex numbers should be from 0 to 4.
	DFS(adj, n);
	cout<<ans;
	return 0;
}
