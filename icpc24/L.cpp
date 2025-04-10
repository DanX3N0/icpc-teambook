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

signed main(){FUN;

   int n;
   cin >> n;

   vi pot(31, 0);

   fore(i,0,n) {
      int x;
      cin >> x;

      int p = 30;

      while(x > 0) {
         if(x & 1) pot[p]++;
         p--;
         x /= 2;
      }

   }
   
   fore(i,0,n) {
      int ans = 0;
      int ppp = 30;

      fore(j,0,31) {
         if(pot[j] > 0) ans += pow(2, 30 - j);
         pot[j]--;
      }

      cout << ans << " ";

   }

   cout << endl;

   re0;
}