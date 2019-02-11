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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int ar[n];
  int ans[1000001];
  memset(ans,0,sizeof(ans));

  REP(i,n)
    cin>>ar[i];
    ans[0] = 1;
    REP(i,n){
        //cout<<"In for : "<<i<<endl;
        for(int j=sqrt(ar[i]);j>=1;j--){
            if(ar[i]%j==0){
                if(j!=ar[i]/j && ar[i]!=1)  ans[ar[i]/j] = (ans[ar[i]/j]%MOD + ans[(ar[i]/j)-1]%MOD)%MOD;
                ans[j] = (ans[j]%MOD + ans[j-1]%MOD)%MOD;
                //cout<<ar[i]<<" i & j : "<<i<<" "<<j<<" ans[j] : "<<ans[j]<<" ans[ar[i]/j] : "<<ans[ar[i]/j]<<endl;
            }
        }

    }
    // REP(i,n+1)
    //     cout<<ans[i]<<" ";
    // cout<<endl;
    long long int fina = 0;
    FOR(i,1,1000001)
        fina = (fina%MOD+ans[i]%MOD)%MOD;
    cout<<fina;
  return 0;
}
