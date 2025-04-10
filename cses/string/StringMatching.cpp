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

vi zF(string& s) {
   int n = s.size();
   vi z(n);
   int l = 0, r = 0;
   for(int i = 1; i < n; i++) {
      if(i <= r) z[i] = min(z[i - l], r - i + 1);
      while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
      if(i + z[i] - 1 > r) {
         l = i;
         r = i + z[i] - 1;
      }
   }
   return z;
}

signed main(){FUN;
  
   string a, b;
   cin >> a >> b;

   string s = b + '#' + a;
   vi z = zF(s);

   int ans = 0;
   for(int l: z) {
      //cout << l << endl;
      if(l == b.size()) ans++;
   }

   cout << ans << endl;

   re0;
}