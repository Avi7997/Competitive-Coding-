#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

#define EPS 1e-14
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INFLL (ll)1e18 //Long long infinity
#define INF (int)1e9 //Int infinity
#define MX 100005

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
typedef vector<string> vstr;

#define us unordered_set
#define um unordered_map
#define bs bitset

typedef vector<um<int, int>> graph;

#define RANGE(i,a,b,d) for (int i=min((int)a,(int)b); i<max((int)a,(int)b); i+=d)
#define RRANGE(i,a,b,d) for (int i=max((int)a,(int)b); i>min((int)a,(int)b); i+=d)
#define FOR(i,a,b) RANGE(i,a,b,1)
#define RFOR(i,a,b) RRANGE(i,a,b,-1)
#define REP(i,s) FOR(i,0,s)
#define RREP(i,s) RFOR(i,s-1,-1)
#define FORIT(it,l) for (auto it = l.begin(); it != l.end(); it++)
#define EACH(x,v) for (auto &x : v)

#define sz(x) (int)(x).size()
#define len(x) (int)sizeof(x)/sizeof(*x)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define contains(m,x) (m.find(x) != m.end()) // check if an element in a map
#define isIn(S, s) (S.find(s) != string::npos) // check if substring

#define pv(v) EACH(x, v) cout << x << " "; cout << endl; // print vector/array
#define pvv(vv) EACH(xx, vv){pv(xx);} // print 2-d vector/2-d array
#define pm(m) EACH(x, m) cout << x.F << ":" << x.S << " "; cout << endl; //print map/lookup table

namespace std{
  // Used for hashing pair
  template <> struct hash<pi> {
    inline size_t operator()(const pi &v) const {
      hash<int> int_hasher;
      return int_hasher(v.F) ^ int_hasher(v.S);
    }
  };
};
int xyz;
// This is min queue
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
void print(T t){
  cout << t << endl;
}

//Python style printing
template<typename T, typename... Args>
void print(T t, Args... args){
  cout << t << " ";
  print(args...);
}

long long int ans = INT_MAX;
long long int dis(int r1, int c1, int r2, int c2){
    return (abs(r1-r2)*abs(r1-r2) + abs(c1-c2)*abs(c1-c2));
}
int isSafe(int M[][50], int row, int col, int visited[][50])
{
    // row number is in range, column number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < xyz) &&
           (col >= 0) && (col < xyz) &&
           (M[row][col]==0 && !visited[row][col]);
}

void DFS(int M[][50], int row, int col, int visited[][50],int de)
{
    // These arrays are used to get row and column numbers of 8 neighbours
    // of a given cell
    static int rowNbr[] = { -1,   0, 0,   1};
    static int colNbr[] = {  0,   -1, 1, 0 };

    // Mark this cell as visited
    if(de == 0) visited[row][col] = 1;
    else visited[row][col] = 2;
    // Recur for all connected neighbours
    for (int k = 0; k < 4; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited) )
            DFS(M, row + rowNbr[k], col + colNbr[k], visited,de);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,r1,r2,c1,c2;
  cin>>n>>r1>>c1>>r2>>c2;
  xyz = n;
  r1--;c1--;r2--;c2--;
  int ar[n][50];
  for(int i=0;i<n;i++){
      string str;
      cin>>str;
      for(int j=0;j<n;j++){
          ar[i][j] = str[j]-'0';
      }
  }

  int visited[n][50];
  memset(visited, 0, sizeof(visited));

  visited[r1][c1] = 1;
  DFS(ar, r1, c1, visited,0);
  if(visited[r2][c2] == 1){   cout<<"0"; return 0;}
  visited[r2][c2] = 2;
  DFS(ar, r2, c2, visited,1);



  // FOR(i,0,n){
  //     FOR(j,0,n)
  //       cout<<visited[i][j]<<" ";
  //   cout<<endl;
  // }

  FOR(i,0,n){
      FOR(j,0,n){
          if(visited[i][j] == 1){
              FOR(p,0,n){
                  FOR(q,0,n){
                      if(visited[p][q] == 2)
                        if(ans>dis(i,j,p,q))
                            ans = dis(i,j,p,q);
                  }
              }
          }
      }
  }
  cout<<ans;
  return 0;
}
