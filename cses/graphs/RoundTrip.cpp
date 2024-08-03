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

const int tam = 1e5 + 1;

vi g[tam];
vi vis(tam, 0);
vi path;

bool dfs(int src, int node, int szPath) {
  if(node == src && szPath >= 3) {
    return true;
  }
  for(auto it: g[node]) {
    if(!vis[it]) {
      path.pb(it);
      vis[it] = 1;
      dfs(src, it, szPath+1);
      path.pop_back();
      vis[it] = 0;
    }
  }
}

signed main(){FUN;

  int n, m;
  cin >> n >> m;

  fore(i,0,m) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }

  fore(i,1,n+1) {
    if(!vis[i]) {
      path.clear();
      vis.clear();
      path.pb(i);
      bool b = dfs(i, i, 1);
      if(b) {
        fore(i,0,sz(path)) {
          cout << path[i] << " ";
        }
        cout << path[0];
        cout << endl;
        exit(0);
      }
    }
  }

  cout << "IMPOSSIBLE" << endl;

}