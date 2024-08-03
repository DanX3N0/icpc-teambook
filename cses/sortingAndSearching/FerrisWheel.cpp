#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FUN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define int long long
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
  // x -> max - w
  int n, x;
  cin >> n >> x;

  vi p(n);

  //weights child's
  fore(i,0,n) cin >> p[i];

  sort(all(p));

  int i = 0, j = n - 1, ans = 0;

  while( i <= j) {
    
    if(p[i] + p[j] <= x) {
      ans++;
      i++;
      j--;
    } else {
      j--;
      ans++;
    }

  }

  cout << ans << endl;

  return 0;
}