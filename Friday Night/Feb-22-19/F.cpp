#include<bits/stdc++.h>
#include<math.h>
#define mod 1000000007
#define gc getchar
using namespace std;
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
    int n,k,arr,i,j,idx;
    scanint(n);
    scanint(k);
    int dp[n];
    double lg[n];
    scanint(arr);
    lg[1]=log(arr);
    dp[1]=arr;
    for(i=2;i<=k+1;i++)
    {
        scanint(arr);
        dp[i]=((long long int)dp[1]*arr)%mod;
        lg[i]=lg[1]+log(arr);
    }
    while(i<=n)
    {
        idx=i-1;
        for(j=i-2;j>=i-k&&j>0;j--)
            if(lg[j]<lg[idx])
                idx=j;
        for(;i<=idx+k&&i<=n;i++)
        {
            scanint(arr);
            dp[i]=((long long int)dp[idx]*arr)%mod;
            lg[i]=lg[idx]+log(arr);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
