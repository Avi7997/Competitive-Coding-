#include<bits/stdc++.h>
using namespace std;

int d[10] = {0,400, 850, 926, 1420, 1540, 1950, 2100, 2400};
int cost[10] = {0, 56, 75, 46, 76,49, 60, 55, 87};
int dp[10];


int solve (int n){
    cout<<n<<" in here"<<endl;
    if(dp[n]!=INT_MAX){
        return dp[n];
    }
    cout<<" here aski : "<<n<<endl;
    int temp = INT_MAX;
    for(int k=0; k<n; k++){
        int x = cost[n] + solve(k) + ((d[n]-d[k]>500)?((d[n]-d[k]-500)/2):0);
        cout<<"n : "<<n<<" k : "<<k<<" : "<<x<<endl;
        if(x<temp){
            temp=x;
        }
    }
    dp[n] = temp;
    return dp[n];
}
int main(){
    //memset(dp,INT_MAX,sizeof(dp));
    for(int i=0; i<10;i++)
        dp[i] = INT_MAX;
    dp[0]=0;
    cout<<solve(8);
    for(int i=0; i<10;i++)
        cout<<dp[i]<<" ";

    return 0;

}
