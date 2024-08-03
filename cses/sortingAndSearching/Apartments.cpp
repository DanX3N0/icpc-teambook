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
  
  int n, m, k;
  cin >> n >> m >> k;

  vi a(n);
  vi b(m); 
  vi check(m+1, 0);

  //desired apartment size
  fore(i,0,n) cin >> a[i];
  //size each apartment
  fore(i,0,m) cin >> b[i];

  sort(all(a));
  sort(all(b));

  int i = 0, j = 0, ans = 0;

  while(i < n && j < m) {
    if(abs(a[i]-b[j]) <= k) {
      i++;
      j++;
      ans++;
    } else {
      if(a[i]-b[j] > k) {
        j++;
      } else {
        i++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}