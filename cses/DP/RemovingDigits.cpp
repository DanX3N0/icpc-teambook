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
#define fore(i, a, b) for (int i = (int) a, o_o = b; i < (int) o_o; ++i)
#define rofe(i, b, a) for (int i = (int) b, o_o = a; i >= (int) o_o; --i)
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
//const int INF = numeric_limits<int>::max()/4;
//const double PI = acos(-1);
const int tam = 1e6 + 7;
vi dp(tam, 1e9);

int solve(int n) {
  fore(i, 1, n + 1) {
    int temp = i;
    while(temp) {
      int dig = temp % 10;
      dp[i] = min(dp[i], 1 + dp[i - dig]);
      temp /= 10;
    }
  }
  return dp[n];
}

signed main(){FUN;
  
  int n;
  cin >> n;
  dp[0] = 0;
  cout << solve(n) << endl;

  return 0;
}