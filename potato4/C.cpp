#include<bits/stdc++.h>
using namespace std;
#define M 1000007
typedef long long int ll;
map<pair<ll,ll>, ll> ma;

ll ans(ll n, ll m, ll k){
        if(ma[make_pair(n,k)] != 0){
            return ma[{n,k}];
        }
        if(n==1 && k<=m)
            return 1;
        if(k>(m*n))
            return 0;
        //cout<<"here"<<n<<" "<<k<<endl;
        ll a = 0;
        for(int i=0;i<=k;i++){
            if(i<=m)
            {
                a += (ans(n-1,m,k-i)%M);
                a = a % M;
                //cout<<a<<endl;
            }
        }
        ma[make_pair(n,k)] = a;
        return a;
}
    
int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    //cout<<n<<m<<k;
    cout<<ans(n,m,k);
    return 0;
}
