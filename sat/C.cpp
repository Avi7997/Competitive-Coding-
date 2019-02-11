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

int a1[1000000][26];
int a2[1000000][26];


//Python style printing
template<typename T, typename... Args>
void print(T t, Args... args){
  cout << t << " ";
  print(args...);
}

void pre(string str1, str2, int n, int m){
    RFOR(l,min(m,n),0){
        FOR(i,0,n-l+1){
            FOR(k,0,l){
                
            }
        }
        FOR(j,0,m-l+1){

        }
    }
}

bool check(string str1, string str2)
{
    // Get lenghts of both strings
    string hi  = str1;
    int n1 = str1.length();
    int n2 = str2.length();

    // quickSort(str1, 0, n1 - 1);
    // quickSort(str2, 0, n2 - 1);
    int ar[26],as[26];
    memset(ar,0,sizeof(ar));
    memset(as,0,sizeof(as));
    //sort(str1.begin(), str1.end());
    //sort(str2.begin(), str2.end());
    // Compare sorted strings
    // string t1 = str1,t2= str2;
    // cout<<str1<<" "<<str2<<endl;
    for(int i=0;i<n1;i++){
        ar[int(str1[i]-'a')]++;
        as[int(str2[i]-'a')]++;
    }
    FOR(i,0,26)
        if(ar[i]!=as[i])
            return false;
       // if (str1.compare(str2) == 0){
       //     cout<<hi<<endl;
       //     return 1;
       // }
      cout<<hi<<endl;
    return 1;
}

void ans(string str1,string str2){
    //cout<<"ans"<<endl;
    int n = str1.length();
    int m = str2.length();
    RFOR(l,min(n,m),0){
        FOR(i,0,n-l+1){
            string te1,te2;
            te1 = str1.substr(i,l);
            FOR(j,0,m-l+1){
                //cout<<l<<" "<<i<<" "<<j<<endl;
                te2 = str2.substr(j,l);
                // char *cstr1 = new char[str1.length() + 1];
                // strcpy(cstr1, str1.c_str());
                // char *cstr2 = new char[str2.length() + 1];
                // strcpy(cstr2, str2.c_str());
                if(check(te1,te2))
                    return;
            }
        }
    }
    cout<<"NONE"<<endl;
}
int main(){
  //freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
    int n;

    cin>>n;
    while(n>0){
        string str1, str2;
        cin>>str1>>str2;
        //cout<<"in"<<endl;
        ans(str1,str2);
        n--;
    }
  return 0;
}
