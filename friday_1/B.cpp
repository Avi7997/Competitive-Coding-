#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    while(n!=0){
        int ar[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ar[i][j];
            }
        }
        int te1=0,te2=0,p,q;
        for(int i=0;i<n;i++){
            int x = ar[i][0];
            for(int j=1;j<n;j++){
                x = x^ar[i][j];
            }
            if(x==1){
                te1++;
                p=i+1;
            }
        }
        for(int i=0;i<n;i++){
            int x = ar[0][i];
            for(int j=1;j<n;j++){
                x = x^ar[j][i];
            }
            if(x==1){
                te2++;
                q=i+1;
            }
        }
        if(te1==0 && te2==0)
            cout<<"OK"<<endl;
        else if(te1==1 && te2 ==1)
            cout<<"Change bit ("<<p<<","<<q<<")"<<endl;
        else
            cout<<"Corrupt"<<endl;
        cin>>n;
    }
    return 0;

}
