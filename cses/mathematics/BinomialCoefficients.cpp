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

const ll MOD = 1000000007;
const ll MAX = 1000007;
ll fact[MAX], inv[MAX];

ll binPow(ll b, ll exp, ll mod) {
   if(exp == 0) return 1;
   if(exp == 1) return b;
   ll ans;
   if(exp % 2 == 0) {
      ans = binPow(b, exp / 2, mod);
      ans = ans * ans % mod;
   }else {
      ans = binPow(b, exp - 1, mod) * b % mod;
   }
   return ans;
}

ll bino(ll n, ll k) {
   // ll a1 = fact[n] * inv[k] % MOD;
   // cout << a1 <<"<-" << endl;
   // ll a2 = a1 * inv[n-k] % MOD;
   // cout << a2 << "<-" << endl;
   // return a2;
   return (((fact[n] * inv[k])%MOD * inv[n -k])%MOD);
}

signed main(){FUN;
  
   ll t;
   cin >> t;

   clr(fact, MAX);
   clr(inv, MAX);

   fact[0] = fact[1] = 1;
   inv[0] = inv[1] = 1;
   fore(i, 2, MAX) {
      fact[i] = (fact[i - 1] * i) % MOD;
      inv[i] = binPow(fact[i], MOD - 2, MOD);
   }

   fore(i, 0, t) {
      ll a, b;
      cin >> a >> b;
      //cout << fact[a] << "]" << inv[b] << "]" << inv[a-b] << endl;
      ll ans = bino(a, b);
      //if(ans < 0) ans += MOD;
      cout << ans << endl;
   }

   re0;
}