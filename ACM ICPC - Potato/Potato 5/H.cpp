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

int n;
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

int dp[195][195][13][13];
int ar[195];
int use[195][195][7];

void prepro(int n){
    for(int i=0;i<n; i++){
        for(int j=i; j<n; j++){
            FOR(k,i,j+1)
                use[i][j][ar[k]]++;
        }
    }
    // REP(i,n)
    //     FOR(j,i,n){
    //         cout<<i<<" "<<j<<" ";
    //         FOR(k,1,7)
    //             cout<<"k->"<<k<<" "<<use[i][j][k]<<" ";
    //         cout<<endl;
    //     }
}

int get(map<int,int> &m, int val){
    int temp=0, i=6;
    while(val>0){
        if(m[i]>0){
            temp+=i;
            m[i]--;
            val--;
        }
        else
            i--;
    }
    return temp;
}

bool fullhouse(map<int,int> &m){
    int yes = 0, yo =0;
    FOR(kind,1,7)
        if(m[kind]>2){
            m[kind]=0;
            yes=1;
            break;
        }
    FOR(kind,1,7)
        if(m[kind]>1){
            m[kind]-=2;
            yo=1;
            break;
        }
    if(yes==1 && yo ==1)
        return true;
    return false;
}

bool small0(map<int, int > &m){
    if((m[1]>0 && m[2]>0 && m[3]>0) || (m[2]>0 && m[3]>0 && m[4]>0) || (m[3]>0 && m[4]>0 && m[5]>0) ||
        (m[4]>0 && m[5]>0 && m[6]>0))
    /*|| (m[2]|m[3]|m[4]) || (m[3]|m[4]|m[5]) || (m[4]|m[5]|m[6]))*/
        return true;
    return false;
}

bool long0(map<int, int > &m){
    if((m[1]>0 && m[2]>0 && m[3]>0 && m[4]>0) || (m[5]>0 && m[2]>0 && m[3]>0 && m[4]>0)
        || (m[6]>0 && m[5]>0 && m[3]>0 && m[4]>0))
        return true;
    return false;
}

bool yantzee(map<int,int> &m){
    if(m[1]>4 || m[2]>4 || m[3]>4 || m[4]>4 || m[5]>4 || m[6]>4)
        return true;
}
int call(int s, int e, int sr, int er){
    int te = 0;
    if(dp[s][e][sr][er]!=-1)
        return dp[s][e][sr][er];
    if(sr==er){
        //cout<<"here "<<sr<<endl;
        map<int, int > m;
        m[1]=0;m[2]=0;m[3]=0;m[4]=0;m[5]=0;m[6]=0;
        FOR(i,1,7)
            m[i]=use[s][e][i];
        int temp=0;
        //cout<<m[1]<<endl;

        if(sr==1 || sr==2 || sr==3 || sr==4 || sr==5 || sr==6){
            //cout<<"1 to 6 "<<sr<<endl;
            temp = sr*min(m[sr],5);
        }

        else if(sr==7){
            //cout<<"in 7 "<<sr<<endl;
            int got =0;
            RFOR(kind,6,0){
                if(m[kind]>2){
                    got=1;
                    temp = kind*3;
                    m[kind] = m[kind]-3;
                }
            }
            if(got==0)
                temp=0;
            else
                temp += get(m,2);
        }

        else if(sr==8){
            //cout<<"in 8 "<<sr<<endl;
            int got =0;
            RFOR(kind,6,0){
                if(m[kind]>3){
                    got=1;
                    temp = kind*4;
                    m[kind] = m[kind]-4;
                }
            }
            if(got==0)
                temp=0;
            else
                temp+=get(m,1);
        }

        else if(sr==9){
            //cout<<"in 9 "<<sr<<endl;
            if(fullhouse(m))
                temp=25;
        }

        else if(sr==10){
            //cout<<"in 10 "<<sr<<endl;
            if(small0(m))
                temp=30;
        }

        else if(sr==11){
            //cout<<"in 11 "<<sr<<endl;
            if(long0(m))
                temp=40;}

        else if(sr==12){
            //cout<<"in 12 "<<sr<<endl;
            temp = get(m,5);
        }

        else if(sr==13){
            //cout<<"in 13 "<<sr<<endl;
            if(yantzee(m))
                temp=50;
        }
        dp[s][e][sr][er] = temp;
        //cout<<s<<" "<<e<<" "<<sr<<" "<<temp<<endl;
        return temp;
    }
    FOR(i,s,min((e-((er-sr)+1)*5)+2,s+17),s+17){
        //cout<<s<<" "<<i+4<<" "<<sr<<" "<<" 2nd part "<<i+5<<" "<<e<<" "<<sr+1<<" "<<er<<" "<<endl;
        int x = (dp[s][i+4][sr][sr]!=-1)?dp[s][i+4][sr][sr]:call(s,i+4,sr,sr);
        int y = (dp[i+5][e][sr+1][er]!=-1)?dp[i+5][e][sr+1][er]:call(i+5,e,sr+1,er);


        if((x+y)>te)
            te=x+y;
    }
    dp[s][e][sr][er] = te;
    return te;
}

int ans(int n){
    return call(0,n-1,1,13);
}

int main(){
  //freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  FOR(i,0,n)
    cin>>ar[i];
    clock_t start = clock();
  memset(dp,-1,sizeof(dp));
  memset(use,0,sizeof(use));
  prepro(n);
  cout<<ans(n);
  clock_t end = clock();
  cout<<((end-start))/CLOCKS_PER_SEC;
  return 0;
}
