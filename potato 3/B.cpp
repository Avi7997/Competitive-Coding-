#include<bits/stdc++.h>
using namespace std;

vector<float> se;
vector<string> str;
vector<pair<float,string>> ulti;

float large(vector<float> array, int n, int y,int idk)
{
    int i,fi,si,ti;
    float firstmin = INT_MAX, secmin = INT_MAX, thirdmin = INT_MAX;
    if(array[0]<array[1]){
      firstmin = array[0];
      secmin = array[1];
      fi = 0;
      si = 1;
    }
    else{
      firstmin = array[1];
      secmin = array[0];
      fi = 1;
      si = 0;
    }
    /* There should be atleast two elements */

    for (int i = 2; i < n; i++)
    {
        /* Check if current element is less than
           firstmin, then update first, second and
           third */
        if (array[i] < firstmin)
        {
            thirdmin = secmin;
            ti = si;
            secmin = firstmin;
            si = fi;
            firstmin = array[i];
            fi = i;
        }

        /* Check if current element is less than
        secmin then update second and third */
        else if (array[i] < secmin)
        {
            thirdmin = secmin;
            ti = si;
            secmin = array[i];
            si = i;
        }

        /* Check if current element is less than
        then update third */
        else if (array[i] < thirdmin){
            thirdmin = array[i];
            ti  = i;
          }
    }
    if(y==1){
      //cout<<fi<<" "<<si<<" "<<ti<<endl;
      //cout<<array[fi]<<" "<<array[si]<<" "<<array[ti]<<endl;
      cout<<str[fi]<<endl<<str[si]<<endl<<str[ti]<<endl;}
    //   if(fi<idk)
    //     cout<<str[fi]<<endl;
    //   else
    //     cout<<str[fi-1]<<endl;
    //
    //   if(si<idk)
    //     cout<<str[si]<<endl;
    //   else
    //     cout<<str[si-1]<<endl;
    //   if(ti<idk)
    //     cout<<str[ti]<<endl;
    //   else
    //     cout<<str[ti-1]<<endl;
    // }
    return firstmin+secmin+thirdmin;
}

int main(){
  int n;
  cin>>n;
  float run[n];
  float sec[n];
  string yz;

  for(int i=0;i<n;i++){
    int x;

    cin>>yz>>run[i]>>sec[i];
    str.push_back(yz);
    se.push_back(sec[i]);

  }
  int idk;
  float ans = 0;
  for(int i=0;i<n;i++){
    se.erase(remove(se.begin(), se.end(), sec[i]), se.end());
    float temp = run[i] + large(se,n-1, 0,0);
    if(temp<ans){
      //cout<<run[i]<<endl;
      //cout<<large(se,n-1,0,0)<<endl;
      ans = temp;
      idk=i;
    }
    se.push_back(sec[i]);
  }
  //se.erase(remove(se.begin(), se.end(), sec[idk]), se.end());
  //cout<<run[idk]<<" "<<large(se,n-1, 0,0)<<endl;
  //cout<<large(se,n-1,0,0)<<endl;
  cout<<ans<<endl<<str[idk]<<endl;
  yz=str[idk];
  // str.erase(remove(str.begin(), str.end(), yz), str.end());
  //float faltu = large(se,n-1,1,idk);
  //min
  for(int i=0;i<n;i++){
    if(i!=idk)
      ulti.push_back( make_pair(sec[i],str[i]) );
  }
  sort(ulti.begin(), ulti.end());
  cout<<ulti[0].second<<endl;
  cout<<ulti[1].second<<endl;
  cout<<ulti[2].second<<endl;
}
