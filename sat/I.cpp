#include<bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

#define EPS 1e-14
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INFLL (ll)1e18 //Long long infinity
#define INF (int)1e9 //Int infinity

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

inline int prev(int i, int n) { return i == 0 ? n-1 : i-1; }
inline int next(int i, int n) { return i == n-1 ? 0 : i+1; }

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

map<string, int>::iterator it;
map<string, int> ans;

string create(int x, int y, int a, int b, int m, int n){
    string str;
    str.append(to_string(x));
    str.append(to_string(y));
    str.append(to_string(a));
    str.append(to_string(b));
    str.append(to_string(m));
    str.append(to_string(n));
    return str;
}

int rev(int x, int y, int a, int b, int m, int n){
    string str = create(x,y,a,b,m,n);
    if(ans.find(str)!=ans.end()){
        ans[str]++;
        return 1;
    }
    return 0;
}
int check(int x, int y, int a, int b, int m, int n){
    string str = create(x,y,a,b,m,n);
    if(ans.find(str)!=ans.end()){
        ans[str]++;
        return 1;
    }
    if(rev(y,x,a,b,n,m))
        return 1;

    str = create(x,y,n,m,a,b);
    if(ans.find(str)!=ans.end()){
        ans[str]++;
        return 1;
    }
    if(rev(y,x,n,m,b,a))
        return 1;

    str = create(x,y,b,a,n,m);
    if(ans.find(str)!=ans.end()){
        ans[str]++;
        return 1;
    }
    if(rev(y,x,b,a,m,n))
        return 1;

    str = create(x,y,m,n,b,a);
    if(ans.find(str)!=ans.end()){
        ans[str]++;
        return 1;
    }
    if(rev(y,x,m,n,a,b))
        return 1;
    return 0;
}

void come(int x, int y, int a, int b, int m, int n){
    string str = create(x,y,a,b,m,n);
    int temp=0;

    if (check(x,y,a,b,m,n)) {
        temp=1;
        return;
    }
    if(check(m,n,a,b,y,x)){
        temp=1;
        return;
    }
    if(check(a,b,y,x,m,n)){
        temp=1;
        return;
    }

    ans[str] = 1;
        //cout<<"in"<<endl;
}

int main(){
  //freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin>>t;

  while(t>0){
      int x,y,a,b,m,n;
      cin>>x>>y>>a>>b>>m>>n;
      come(x,y,a,b,m,n);
      t--;
  }
  //cout<<"here";
  int yeh = 0;
  for ( it = ans.begin(); it != ans.end(); it++ )
    {
    if(yeh<it->second)
        yeh = it->second;
    }
    cout<<yeh;
  return 0;
}
