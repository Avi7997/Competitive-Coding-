#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  string str;
  int ar[n];
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>str;
    ar[i] = stoi(str,NULL,2);
    //cout<<(stoi(str,NULL,2)&16);
  }
  cout<<"here";
  for(int i=k-1;i>=0;i--){
    int c1 = 0,c2 = 0;
    int x = (1<<i);
    for(int j=0;j<n;j++){
       if(x&ar[j])
         c2++;
       else
         c1++;
    }
    if(c2>c1)
      cout<<"0";
    else
      cout<<"1";
  }
  return 0;
}
