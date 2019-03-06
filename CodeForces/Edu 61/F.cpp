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
um<string, int> m;

string helper(string str){
    string ans;
    int n = str.length();
    ans += str[0];
    for(int i = 1; i<n; i++){
        if(str[i] != str[i-1])
            ans += str[i];
    }
    return ans;
}
int sol(string str){
    if(str.length()==1)
        return 1;
    if(contains(m,str))
        return m[str];
    int ans = INT_MAX, mim  =INT_MAX;
    // for(int i=0; i<str.length();i++){
    //     ans = 1;
    //     while()
    //     string str2 = str.substr(0,i);
    //     str2 += str.substr(i+1,str.length()-i-1);
    //     str2 = helper(str2);
    //     ans += sol(str2);
    //     if(ans<min)
    //         min = ans;
    // }
    int i=1, j=str.length()-2;

    while(i<str.length() && str[i] == str[i-1])
        i++;

    while(j>=0 && str[j] == str[j+1])
        j--;
        if(str == "bac")    cout<<"here : "<<i<<" "<<j<<endl;
    if(str[0] == str[str.length()-1]){
        if(j<i)
            ans = 0;
        else{
            ans = sol(str.substr(i, j-i+1));
            mim = min(sol(str.substr(i,str.length() - i)), sol(str.substr(0, j+1)));
        }
    }
    else{
        mim = min(sol(str.substr(i,str.length() - i)), sol(str.substr(0, j+1)));
    }
    cout<<str<<" "<<ans<<" "<<mim<<endl;
    ans = min(ans, mim);

    cout<<str<<ans+1<<endl<<endl;
    m[str] = ans+1;
    return ans+1;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string str;
  cin>>n>>str;
  //cout<<helper(str);
  cout<<sol(str);
  return 0;
}
