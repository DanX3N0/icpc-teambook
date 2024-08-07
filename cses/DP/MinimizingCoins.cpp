#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FUN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define clr(a,h) memset(a,(h),sizeof(a))
#define f first
#define s second
#define fore(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
#define rofe(i,a,b) for(int i = (int)b, o_o = a; i >= (int) o_o; --i)
#define sz(x) (int) x.size()
#define endl '\n'
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = numeric_limits<int>::max()/4;
const double PI = acos(-1);

int solve(int x, int n, vi &c) {

  vi dp((x+1), INF);
  dp[0] = 0;

  fore(i,1,(x+1)){
    fore(j,0,n) {
      if(c[j] > i || dp[i-c[j]]==INF) continue;
      dp[i]=min(dp[i],dp[i-c[j]]+1);
    }
  }

  if(dp[x]!= INF) return dp[x];

  return -1;
}

signed main(){FUN;
  
  int n,x;
  cin>>n>>x;
  vi c(n);
  fore(i,0,n) cin>>c[i];
  int ans = solve(x,n,c);
  cout << ans << endl;
  return 0;
}