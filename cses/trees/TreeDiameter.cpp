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

const int tam = 2e5 + 7;

vvi tree(tam);
vi dist(tam, 0);

void dfs(int node, int parent) {
   for(auto it: tree[node]) {
      if(it != parent) {
         dist[it] = dist[node] + 1;
         dfs(it, node);
      }
   }
}

signed main(){FUN;
  
   int n;
   cin >> n;

   fore(i, 0, n - 1) {
      int a, b;
      cin >> a >> b;
      tree[a].pb(b);
      tree[b].pb(a);
   }

   dfs(1, 0);

   int maxDist = -1, node = 0;

   fore(i, 1, n + 1) {
      if(dist[i] > maxDist) {
         maxDist = dist[i];
         node = i;
      }
   }

   fore(i, 0, n + 1) dist[i] = 0;

   dfs(node, 0);

   fore(i, 0, n + 1) {
      maxDist = max(maxDist, dist[i]); 
   }

   cout << maxDist << endl;

   re0;
}