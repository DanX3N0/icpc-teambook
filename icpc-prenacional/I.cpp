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

const int MOD = 1000000007;
const int tam = 100001;

int p[tam]; // padre de cada nodo
int _rank[tam]; // altura del arbol
int cant[tam]; // cantidad de elementos en cada conjunto

int findParent(int v) {
  if (p[v] == -1) return v;
  //int rep = findParent(p[v]);
  //p[v] = rep;
  //return rep;
  return p[v] = findParent(p[v]); // version corta
}

void join(int a, int b) {
  a = findParent(a);
  b = findParent(b);
  if (a == b) return; // a y b estan en el mismo conjunto
  // Sin union por rango
  //p[a] = b;
  //cant[b] += cant[a];

  // Union by Rank
  if (_rank[a] > _rank[b]) {
    p[b] = a;
    // Ahora a es el representante
    _rank[a] = max(_rank[a], _rank[b] + 1);
    cant[a] = ((cant[a] % MOD) + (cant[b] % MOD)) % MOD;
  }
  else {
    p[a] = b;
    // Ahora b es el representante
    _rank[b] = max(_rank[b], _rank[a] + 1);
    cant[b] = ((cant[b] % MOD) + (cant[a] % MOD)) % MOD;
  }
}

signed main() {
  FUN;
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  memset(p, -1, sizeof p);
  clr(_rank, 0);
  fore(i, 0, tam) cant[i] = 1;

  int n, m;
  cin >> n >> m;

  fore(i, 0, m) {
    int i1, i2;
    cin >> i1 >> i2;
    join(i1, i2);
  }

  set<int> st;

  int ans = 1;

  fore(i, 1, n + 1) {
    if(st.count(findParent(i))) {
      continue;
    } else {
      st.insert(findParent(i));
      ans = (ans * cant[findParent(i)]) % MOD;
    }
  }

  cout << ans << endl;

  return 0;
}