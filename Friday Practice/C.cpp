#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int ar[3][2];
	bool ar1[101], ar2[101], ar3[101];
	memset(ar1, 0, sizeof(ar1));
	memset(ar2, 0, sizeof(ar2));
	memset(ar3, 0, sizeof(ar3));
	for(int i=0;i<3;i++)
		for(int j=0;j<2;j++){
			cin>>ar[i][j];
		}
	for(int i = ar[0][0]; i< ar[0][1]; i++)
		ar1[i] = 1;
	for(int i = ar[1][0]; i< ar[1][1]; i++)
		ar2[i] = 1;
	for(int i = ar[2][0]; i< ar[2][1]; i++)
		ar3[i] = 1;
	int ans = 0;

	for(int k=1; k<=100; k++){
		if((ar1[k]&&ar2[k]&&ar3[k])){
			ans+=3*c;
			//cout<<"IN All 3 "<<k<<endl;
		}
		else if((ar1[k]&&ar2[k]) || (ar2[k]&&ar3[k]) || (ar3[k]&&ar1[k])){
			ans+=2*b;
			//cout<<"IN All 2 "<<k<<endl;
		}
		else if(ar1[k]==1 || ar2[k]==1 || ar3[k]==1){
			//cout<<"IN Just one "<<k<<endl;
			ans+=a;
		}
		if(k==100)
			break;
	}
	//cout<<"HERERERERER";
	cout<<ans;
return 0;
}
