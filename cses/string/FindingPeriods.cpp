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
//const int MOD = 1000000007;

const ll prime = 455577;
const ll MOD = 1e9 + 7;

signed main(){FUN;
  
   string s;
   cin >> s;
   int n = s.size();

   vector<ll> basePow(n);
   basePow[0] = 1;
   fore(i, 1, n) basePow[i] = (basePow[i - 1] * prime) % MOD;

   vector<ll> pref(n + 1);
   fore(i, 1, n + 1) pref[i] = (pref[i - 1] * prime + s[i - 1]) % MOD;

   auto getHash = [&](int l, int r) -> ll{
      ll h = (pref[r + 1] - (basePow[r - l + 1] * pref[l] % MOD) % MOD);
      return h < 0 ? (h + MOD) : h;
   };

   fore(i, 0, n) {
      int currIdx = 0;
      bool ok = 1;
      while(currIdx < n) {
         int len = min(i + 1, n - currIdx);
         ok &= getHash(0, len - 1) == getHash(currIdx, currIdx + len - 1);
         currIdx += len;
      }
      if(ok) cout << i + 1 << ' ';
   }

   cout << endl;

   re0;
}