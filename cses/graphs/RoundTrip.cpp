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

const int MAX = 100007;

vi adj[MAX];
bool vis[MAX];
int parent[MAX];

bool dfs(int v, int p, vi& cycle) {

   vis[v] = 1;
   parent[v] = p;
   for(auto u: adj[v]) {
      if(u == p) continue;
      if(vis[u]) {
         cycle.pb(u);
         for(int cur = v; cur != u; cur = parent[cur]) {
            cycle.pb(cur);
         }
         cycle.pb(u);
         return true;
      }
      if(!vis[u] && dfs(u, v, cycle)) {
         return true;
      }
   }
   return false;
}

signed main(){FUN;
  
   int n, m;
   cin >> n >> m;

   fore(i, 0, m) {
      int a, b;
      cin >> a >> b;
      adj[a].pb(b);
      adj[b].pb(a);
   }

   vi cycle;

   fore(i, 1, n + 1) {
      if(!vis[i] && dfs(i, -1, cycle)) {
         break;
      }
   }

   if(cycle.empty()) {
      cout << "IMPOSSIBLE" << endl;
   } else {
      cout << cycle.size() << endl;
      for(int v: cycle) {
         cout << v << " ";
      }
      cout << endl;
   }

   re0;
}