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

bool mycomp(pair<int,int> a, pair<int,int> b)
{   return a.F > b.F; }

int mergeIntervals(vector<pair<int,int>> &arr, int n)
{
    // Sort Intervals in decreasing order of
    // start time
    sort(arr.begin(), arr.end(), mycomp);
    int index = 0; // Stores index of last element
    // in output array (modified arr[])

    // Traverse all input Intervals
    for (int i=0; i<n; i++)
    {
        // If this is not first Interval and overlaps
        // with the previous one
        if (index != 0 && arr[index-1].F <= arr[i].S)
        {
            while (index != 0 && arr[index-1].F <= arr[i].S)
            {
                // Merge previous and current Intervals
                arr[index-1].S = max(arr[index-1].S, arr[i].S);
                arr[index-1].F = min(arr[index-1].F, arr[i].F);
                index--;
            }
        }
        else // Doesn't overlap with previous, add to
            // solution
            arr[index] = arr[i];

        index++;
    }

    // Now arr[0..index-1] stores the merged Intervals
    // cout << "\n The Merged Intervals are: ";
    // for (int i = 0; i < index; i++)
    //     cout << "[" << arr[i].F << ", " << arr[i].S << "] ";

    return index;
}
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);

    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> so;
    vector<pair<int,int>> un;

    for(int i=0; i<m; i++){
        int t,l,r;
        cin>>t>>l>>r;
        if(t == 1)
            so.pb(mp(l,r));
        else
            un.pb(mp(l,r));
    }
    // cout<<so.size()<<endl;
    int xyz = mergeIntervals(so, so.size());


    vector<bool> paint(n,0);
    for(int i=0; i<xyz; i++){
        for(int j=so[i].F; j<=so[i].S; j++){
            paint[j-1] = true;
        }
    }

    vector<int> cu(n);

    cu[0] = (paint[0])?1:0;
    for(int i=1;i<n;i++){
        if(paint[i])
            cu[i] = cu[i-1]+1;
        else
            cu[i] = cu[i-1];
    }

    for(int i=0; i<un.size(); i++){
        int s = un[i].F;
        int e = un[i].S;
        for(int j=0; j<xyz; j++){
            if(so[j].F <= s && so[j].S >= e){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        // if((s-e) == (cu[s] - cu[e])){
        //     cout<<"NO";
        //     return 0;
        // }
    }
    vector<pair<int,int>> nex(xyz);
    for(int i=xyz-1; i>=0; i--){
        nex[xyz-i-1] = so[i];
    }
    cout<<"YES"<<endl;
    int end = 0;
    for(int i=0; i<xyz; i++){

        int s = nex[i].F;
        int e = nex[i].S;
        int cnt = 999;
        for(int j=end+1; j<s; j++){
            cout<<cnt<<" ";
            cnt--;
        }

        int count = 1;
        for(int j=s; j<e; j++){
            cout<<count<<" ";
            count++;
        }
        cout<<"1000 ";
        end = e;
    }
    int cnt = 999;
    for(int j=end+1; j<=n; j++){
        cout<<cnt<<" ";
        cnt--;
    }

  	return 0;
}
