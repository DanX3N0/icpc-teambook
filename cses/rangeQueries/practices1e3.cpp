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

struct ms {
  int m, n;
};

struct segtree {

  int size;
  vector<ms> t;

  void init(int n) {
    size = 1;
    while(size < n) size *= 2;
    t.resize(2 * size);
  }

  ms merge(ms a, ms b) {
    if(a.m == b.m) {
      return {a.m, a.n + b.n};
    } else if(a.m > b.m) {
      return {b.m, b.n};
    } else {
      return {a.m, a.n};
    }
  }

  void build(vi &a, int x, int lx, int rx) {
    if(rx - lx == 1) {
      if(lx < sz(a)) t[x] = {a[lx], 1};
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }

  void build(vi &a) {
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if(rx - lx == 1) {
      t[x] = {v, 1};
      return;
    }
    int m = (lx + rx) / 2;
    if(i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  ms getMin(int l, int r, int x, int lx, int rx) {
    if(lx >= r || l >= rx) return {INT_MAX, 0};
    if(lx >= l && rx <= r) return t[x];
    int m = (lx + rx) / 2;
    ms s1 = getMin(l, r, 2 * x + 1, lx, m);
    ms s2 = getMin(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
  }

  ms getMin(int l, int r) {
    return getMin(l, r, 0, 0, size);
  }

};

int main(){FUN;
  
  int n, q;
  cin >> n >> q;

  segtree st;

  vi a(n);
  fore(i, 0, n) {
    int v; cin >> v;
    a[i] = v;
  }

  st.init(n);
  st.build(a);

  while(q--) {
    int op; cin >> op;
    if(op == 1) {
      int k, u;
      cin >> k >> u;
      st.set(k, u);
    } else {
      int l, r;
      cin >> l >> r;
      auto ans = st.getMin(l, r);
      cout << ans.m << " " << ans.n << endl;
    }
  }

  return 0;
}