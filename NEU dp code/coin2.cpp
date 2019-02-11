// C++ program to find value of f(n) where f(n)
// is defined as
// F(n) = F(n-1) + F(n-2) + F(n-3), n >= 3
// Base Cases :
// F(0) = 0, F(1) = 1, F(2) = 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

ll a,b,c,d;
ll count1[10];
ll F[10][10];

// A utility function to multiply two matrices
// a[][] and b[][]. Multiplication result is
// stored back in b[][]
void multiply(ll x[10][10], ll y[10][10])
{
    //cout<<"times";
	// Creating an auxiliary matrix to store elements
	// of the multiplication matrix
	ll mul[10][10];
	for (ll i = 0; i < 10; i++)
	{
		for (ll j = 0; j < 10; j++)
		{
			mul[i][j] = 0;
			for (ll k = 0; k < 10; k++)
				mul[i][j] = (mul[i][j]%MOD + ((x[i][k]%MOD)*(y[k][j]%MOD))%MOD)%MOD;
		}
	}

	// storing the muliplication resul in a[][]
	for (ll i=0; i<10; i++)
		for (ll j=0; j<10; j++)
			F[i][j] = mul[i][j]; // Updating our matrix
}

// Function to compute F raise to power n-2.
ll power(ll n)
{
	//ll M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
    ll M[10][10];
    memset(M,0,sizeof(M));
    for(ll i=1;i<10;i++)
        M[i][i-1] =1;
    M[0][a-1] = 1;
    M[0][b-1] = 1;
    M[0][c-1] = 1;
    M[0][d-1] = 1;

	// Multiply it with initial values i.e with
	// F(0) = 0, F(1) = 1, F(2) = 1
	if (n==1){
        ll ans = 0;
        for(int i =0;i<10;i++){
            ans = (ans%MOD + ((F[0][i]%MOD)*(count1[9-i]%MOD)))%MOD;
        }
		return ans;
    }
	power(n/2);

	multiply(F, F);

	if (n%2 != 0)
		multiply(F, M);

	// Multiply it with initial values i.e with
	// F(0) = 0, F(1) = 1, F(2) = 1
    ll ans = 0;
    for(int i =0;i<10;i++){
        ans = (ans%MOD + ((F[0][i]%MOD)*(count1[9-i]%MOD)))%MOD;
    }
    // if(n==4){
    //     for(int i=0;i<10;i++)
    //         cout<<"values : "<<F[0][i]<<" "<<count1[9-i]<<endl;
    //     cout<<"it ends here"<<endl;
    // }
	//return F[0][10-a]*count1[10-a] + F[0][10-b]*count1[10-b] + F[0][10-c]*count1[10-c] +F[0][10-d]*count1[10-d];
    return ans;
}

// Return n'th term of a series defined using below
// recurrence relation.
// f(n) is defined as
// f(n) = f(n-1) + f(n-2) + f(n-3), n>=3
// Base Cases :
// f(0) = 0, f(1) = 1, f(2) = 1
ll findNthTerm(ll n)
{
	//ll F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;

    memset(F,0,sizeof(F));
    for(ll i =1;i<10;i++)
        F[i][i-1] =1;
    F[0][a-1] = 1;
    F[0][b-1] = 1;
    F[0][c-1] = 1;
    F[0][d-1] = 1;

 	return power(n-9);
}


ll countWays(ll arr[], ll m, ll N)
{

    memset(count1, 0, sizeof(count1));

    // base case
    count1[0] = 1;

    // count ways for all values up
    // to 'N' and store the result
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < m; j++)

            // if i >= arr[j] then
            // accumulate count for value 'i' as
            // ways to form value 'i-arr[j]'
            if (i >= arr[j])
                count1[i] = (count1[i]%MOD +  count1[i - arr[j]]%MOD) %MOD;

    // required number of ways
    // for(int i=0;i<10;i++)
    //     cout<<count1[i]<<" ";
    // cout<<endl;
    return count1[N];

}

// Driver code
int main()
{
    ll arr[4];
    ll n;
	cin>>a>>b>>c>>d>>n;
    //a = 2; b = 3; c = 5; d = 7;
    arr[0] = a; arr[1] = b; arr[2] =c; arr[3]=d;
    countWays(arr, 4, 9);
    //cout << findNthTerm(n);
	if(n<10)
		cout<<count1[n];
	else
    	cout<<findNthTerm(n);
    return 0;
}
