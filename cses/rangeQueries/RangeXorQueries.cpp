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
#define fore(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
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

const int INF = numeric_limits<int>::max()/4;
const double PI = acos(-1);

struct segtree {

  int size;
  vector<ll> sums;

  void init(int n) {
    size = 1;
    while(size < n) size *= 2;
    sums.assign(2 * size, 0LL);
  }

  void build(vi &a, int x, int lx, int rx) {
    if(rx - lx == 1) {
      if(lx < sz(a)) sums[x] = a[lx];
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    sums[x] = sums[2 * x + 1] ^ sums[2 * x + 2];
  }

  void build(vi &a) {
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if(rx - lx == 1) {
      sums[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if(i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    sums[x] = sums[2 * x + 1] ^ sums[2 * x + 2];
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  ll sum(int l, int r, int x, int lx, int rx) {
    if(lx >= r || l >= rx) return 0;
    if(lx >= l && rx <= r) return sums[x];
    int m = (lx + rx) / 2;
    ll s1 = sum(l, r, 2 * x + 1, lx, m);
    ll s2 = sum(l, r, 2 * x + 2, m, rx);
    return s1 ^ s2;
  }

  ll sum(int l, int r) {
    return sum(l, r, 0, 0, size);
  }

};

int main(){FUN;
  
  int n, m;
  cin >> n >> m;

  segtree st;

  vi a(n);
  fore(i, 0, n) {
    int v; cin >> v;
    a[i] = v;
  }

  st.init(n);
  st.build(a);

  while(m--) {
    int l, r;
    cin >> l >> r;
    l--; // 0 based
    cout << st.sum(l, r) << endl;
  }

  return 0;
}