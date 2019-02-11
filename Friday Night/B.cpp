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

int check(pair<float,float> p, pair<float,float> p1, pair<float,float> p2){
    float d ;
    d =  (p.first - p1.first)*(p2.second-p1.second)-(p.second-p1.second)*(p2.first-p1.first);
    if(d>0)
        return 1;
    else if(d<0)
        return 0;
    return -1;
}

bool online(pair<float,float> p, pair<float,float> p1, pair<float,float> p2){
    int t1=0,t2=0;
    if(check(p,p1,p2)!=-1)
        return 0;
    if(p1.first<p2.first){
        if(p1.first<=p.first && p.first<=p2.first)
            t1=1;}
    else{
        if(p2.first<=p.first && p.first<=p1.first)
            t1=1;}
    if(p1.second<p2.second){
        if(p1.second<=p.second && p.second<=p2.second)
            t2=1;}
    else{
        if(p2.second<=p.second && p.second<=p1.second)
            t2=1;}
    if(t1 == 1 && t2==1)
        return 1;
    return 0;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  float n,d;
  cin>>n>>d;
  pair<float,float> p1,p2,p3,p4;
  p1.first = 0; p1.second = d;
  p2.first = d; p2.second = 0;
  p3.first = n; p3.second = n-d;
  p4.first = n-d; p4.second = n;

  int t;
  cin>>t;
  while(t>0){
      pair<float,float> p;
      cin>>p.first>>p.second;
      //cout<<p.first<<" "<<p.second<<endl;
      if(online(p,p1,p2) || online(p,p2,p3) || online(p,p3,p4) || online(p,p1,p4))
        cout<<"YES"<<endl;
    else{
        //cout<<check(p,p1,p2)<<" "<<check(p,p3,p4)<<" "<<check(p,p2,p3)<<" "<<check(p,p1,p4)<<endl;
        //cout<<check(p,p3,p4)<<" "<<check(p,p4,p3)<<endl;
        if(check(p,p1,p2)^check(p,p4,p3) && check(p,p2,p3)^check(p,p1,p4)){
            if(check(p3,p1,p2) == check(p,p1,p2) && check(p1,p2,p3)==check(p,p2,p3))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
      t--;
  }

  return 0;
}
