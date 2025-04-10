#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FUN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define int long long
#define re0 return 0
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

signed main(){FUN;
  
   string a,b;
   cin >> a >> b;

   int n = a.size();
   int m = b.size();

   vvi dp(n + 1, vi(m + 1, INT32_MAX));

   dp[0][0] = 0;

   fore(i, 0, n + 1) {
      fore(j, 0, m + 1) {
         if(i != 0) {
            //delete i - 1 from the string
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
         }

         if(j != 0) {
            //add letter j - 1 of the result to the string
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
         }
         //make letter i - 1 equal to letter j - 1
         if(i != 0 && j != 0) {
            int newCost = dp[i-1][j-1] + (a[i - 1] != b[j - 1]);
            dp[i][j] = min(dp[i][j], newCost);
         }  

      }
   }

   cout << dp[n][m] << endl;

   re0;
}