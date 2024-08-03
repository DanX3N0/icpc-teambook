#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;++i)
#define vi vector<int>

int main(){

  int n;cin>>n;
  vi v;
  int nn=n;
  fore(i,2,nn+1){
    while(n%i==0){
      v.push_back(i);
      n/=i;
    }
  }

  fore(i,0,v.size()) {
    if(i<v.size()-1){
      cout<<v[i]<<"x";
    }else cout<<v[i]<<endl;
  }
  
  return 0;
}