#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
#define ll long long




// function to c the total
// number of ways to sum up to 'N'
ll cWays(ll arr[], ll m, ll N)
{
    ll c[100];
    memset(c, 0, sizeof(c));
    // base case
    c[0] = 1;

    // c ways for all values up
    // to 'N' and store the result
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < m; j++)

            // if i >= arr[j] then
            // accumulate c for value 'i' as
            // ways to form value 'i-arr[j]'
            if (i >= arr[j])
                c[i] = (c[i]%MOD +  c[i - arr[j]]%MOD) %MOD;

    // required number of ways
    return c[N];

}

// Driver code
int main()
{
    ll arr[4];
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
    ll N;
    ll m = 4;
    cin>>N;
    for(int i=0; i<=25; i++)
    cout  << cWays(arr, m, i)<<" ";
    cout<<endl;
    return 0;
}
