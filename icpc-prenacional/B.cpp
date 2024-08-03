#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;++i)
#define vi vector<int>

int main(){

  int q;cin>>q;
  while(q--){
    int k;cin>>k;
    vi v(k);
    fore(i,0,k) cin>>v[i];

    long long ans = 0;

    fore(i,0,k) ans += (long long)(pow(2,(v[i]-1)));
    cout<<ans<<endl;
  }

  return 0;
}