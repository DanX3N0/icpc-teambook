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

const int MAX = 200007;

int n;
int segtree[4 * MAX], a[MAX];

void build(int l = 1, int r = n, int node = 1) {
   if(l == r) segtree[node] = a[l];
   else {
      int mid = (l + r) / 2;
      build(l, mid, node * 2);
      build(mid + 1, r, node * 2 + 1);
      segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
   }
}

void queryUpdate(int val, int l = 1, int r = n, int node = 1) {
   if(l == r) {
      segtree[node] -= val;
      cout << l << ' ';
   } else {
      int mid = (l + r) / 2;
      if(segtree[node * 2] >= val) queryUpdate(val, l, mid, node * 2);
      else queryUpdate(val, mid + 1, r, node * 2 + 1);
      segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
   }
}

signed main(){FUN;
  
   int q;
   cin >> n >> q;
   fore(i, 1, n + 1) cin >> a[i];
   build();

   while(q--) {
      int x;
      cin >> x;
      if(segtree[1] < x) cout << "0 ";
      else queryUpdate(x); 
   }

   re0;
}