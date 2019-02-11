#include<bits/stdc++.h>
using namespace std;

#define contains(m,x) (m.find(x) != m.end())

int main(){

    long long int n,m,te=INT_MIN,temp,ans=0;

    cin>>n>>m;
    map<int, int> ma;
    long long int ar[n];

    for(int i=0; i<n; i++){
        cin>>ar[i];
        ans+=ar[i];
        if(te<ar[i])    te = ar[i];
        if(contains(ma,ar[i])) ma[ar[i]]++;
        else ma[ar[i]] =1;
    }
    //if(n==1) cout<<"0";
    //else{
        sort(ar,ar+n);
        int j =1;
        for(int i=0;i<n;i++){
            if(ar[i]>=j)
                j++;
        }
        //cout<<"te : "<<te<<" j : "<<j<<endl;
        if(j>te) j = te+1;
        cout<<ans-(j-1)-(n-j+1)-(te-j+1);
    //}
    return 0;
}
