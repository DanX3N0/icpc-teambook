#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FUN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define int long long
#define re0 return 0
#define eb emplace_back
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

const int tam = 1e5 + 7;

vvii g(tam);
vi vis;
vi path;

void dfs(int node) {

   while(!g[node].empty()) {
      auto [it, idx] = g[node].back();
      g[node].pop_back();
      if(vis[idx]) continue;
      vis[idx] = 1;
      dfs(it);
   }
   path.pb(node);
}

signed main(){FUN;
   int n, m;
   cin >> n >> m;

   vi degree(n + 1, 0);
   vis.resize(m + 1, 0);

   fore(i, 0, m) {
      int a, b;
      cin >> a >> b;
      int id = i + 1;
      g[a].eb(mp(b, id));
      g[b].eb(mp(a, id));
      degree[a]++;
      degree[b]++;
   }

   fore(i, 1, n + 1) {
      if(degree[i] % 2 != 0) {
         cout << "IMPOSSIBLE" << endl;
         exit(0);
      }
   }

   dfs(1);

   if(sz(path) != m + 1) {
      cout << "IMPOSSIBLE" << endl;
   } else {
      for(auto node : path) cout << node << ' ';
      cout << endl;
   }

   re0;
}