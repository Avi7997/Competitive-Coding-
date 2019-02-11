#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void multiply(ll x[10][10], ll y[10][10]){
    ll mul[10][10];
	for (ll i = 0; i < 10; i++)
	{
		for (ll j = 0; j < 10; j++)
		{
			mul[i][j] = 0;
			for (ll k = 0; k < 10; k++)
				mul[i][j] += x[i][k]*y[k][j];
		}
	}

	// storing the muliplication resul in a[][]
	for (ll i=0; i<10; i++)
		for (ll j=0; j<10; j++)
			x[i][j] = mul[i][j];
}
void prin(ll F[10][10]){
    for (ll i = 0; i < 10; i++)
	{
		for (ll j = 0; j < 10; j++)
		{
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    ll F[10][10];
    memset(F,0,sizeof(F));
    for(ll i =1;i<10;i++)
        F[i][i-1] =1;
    F[0][1] = 1;
    F[0][2] = 1;
    F[0][4] = 1;
    F[0][6] = 1;
    prin(F);
    multiply(F,F);
    multiply(F,F);
    multiply(F,F);
    cout<<endl;
    prin(F);
    return 0;

}
