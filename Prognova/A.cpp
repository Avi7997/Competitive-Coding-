#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int z = str.length();
    int n;
    cin>>n;
    z = z-n;
    int y = n+1;
    //cout<<z<<" "<<y<<" "<<z-y;

    if(z-y >= -1)
        cout<<"Yes";
    else{
        string xyz =str;
        sort(str.begin(), str.end());
        int tep = 0;
        //cout<<str<<" "<<xyz <<" "<<z<<" "<<y-2<<endl;
        for(int p = z; p<y-1; p++){
            if(xyz[p] != str[p]){
                tep =  1;
                cout<<"No";
                break;
            }
        }
        if(tep == 0)
        cout<<"Yes";
    }

    return 0;
}
