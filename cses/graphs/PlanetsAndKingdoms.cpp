#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FUN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
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

const int tam = 1e5 + 7;
vvi g(tam);
vi vis(tam, 0);
stack<int> st;
vvi adjT(tam);
int kingdom = 1;
vii kingdomsArray;

void dfs1(int node) {
   vis[node] = 1;
   for(auto it: g[node]) {
      if(!vis[it]) {
         dfs1(it);
      }
   }
   st.push(node);
}

void dfs2(int node) {
   vis[node] = 1;
   for(auto it: adjT[node]) {
      if(!vis[it]) {
         dfs2(it);
      }
   }
   kingdomsArray.pb({node, kingdom});
}

int kosaraju(int n) {
   
   fore(i, 1, n + 1) {  
      if(!vis[i]) {
         dfs1(i);
      }
   }

   fore(i, 1, n + 1) {
      vis[i] = 0;
      for(auto it: g[i]) {
         adjT[it].pb(i);
      }
   }

   int scc = 0;

   while(!st.empty()) {
      int node = st.top();
      st.pop();
      if(!vis[node]) {
         scc++;
         dfs2(node);
         kingdom++;
      }
   }

   return scc;

}

signed main(){FUN;
   g.clear();
   adjT.clear();

   int n, m;
   cin >> n >> m;

   fore(i, 0, m) {
      int a, b;
      cin >> a >> b;
      g[a].pb(b);
   }

   int ans = kosaraju(n);

   cout << ans << endl;

   sort(all(kingdomsArray));

   fore(i, 0, sz(kingdomsArray)) cout << kingdomsArray[i].s << " ";
   cout << endl;

   re0;
}