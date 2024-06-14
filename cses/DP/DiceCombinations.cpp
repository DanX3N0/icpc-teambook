#include<bits/stdc++.h>
using namespace std;

#define fore(i,a,b) for(int i=a;i<b;i++)
#define ll long long

const ll MOD = 1000000007;
const ll MAX = 10000000;
vector<int> dp(MAX, 0);

int main(){

  int n;cin>>n;
  dp[0] = 1;
  fore(i,1,n+1) fore(j,1,7) if(i-j>=0) dp[i] = (dp[i] + dp[i-j]) % MOD;

  cout<<dp[n]<<endl;

  return 0;
}