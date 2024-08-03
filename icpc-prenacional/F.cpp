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
#define pb push_back
#define fore(i, a, b) for (int i = (int) a, o_o = b; i < (int) o_o; ++i)
#define rofe(i, b, a) for (int i = (int) b, o_o = a; i >= (int) o_o; --i)
#define sz(x) (int) x.size()
#define endl '\n'
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
//const int INF = numeric_limits<int>::max()/4;
//const double PI = acos(-1);

int dom[100005];
int pos[100005];
int vis[100005];

signed main() {
  FUN;

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  clr(dom, 0);
  clr(pos, 0);
  clr(vis, 0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    fore(i, 0, n) cin >> dom[i];
    fore(i, 0, n - 1) cin >> pos[i];

    int sum = 0;
    bool lr = false;

    rofe(i, n - 2, 0) {
      if(sum > 0) {
        if(dom[i] > sum + pos[i]) {
          sum = 0; 
        } else {
          sum += pos[i];
        }
      } else {
        if(dom[i] <= pos[i]) {
          sum += pos[i];
        }
      }
      if(i == 0 && sum == 0) lr = true;
    }

    sum = 0;
    bool rl = false;

    fore(i, 0, n - 1) {
      if(sum > 0) {
        if(dom[i+1] > sum + pos[i]) {
          sum = 0;
        } else {
          sum += pos[i];
        }
      } else {
        if(dom[i+1] <= pos[i]) {
          sum += pos[i];
        }
      }
      if(i == n - 2 && sum == 0) rl = true;
    }

    if(lr || rl) cout << "habibi" << endl;
    else cout << "which" << endl;

  }

  return 0;
}