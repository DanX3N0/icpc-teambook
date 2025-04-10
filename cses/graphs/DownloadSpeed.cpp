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

const int tam = 507;

vvi adj(tam);
vector<vector<ll>> capacity(tam, vector<ll>(tam, 0));

ll maxFlow(int source, int sink) {
   int n = adj.size();
   vi parent(n + 1, -1);
   auto reachable = [&]() -> bool {
      queue<int> q;
      q.push(source);
      while(!q.empty()) {
         int node = q.front();
         q.pop();
         for(auto child: adj[node]) {
            ll w = capacity[node][child];
            if(w <= 0 || parent[child] != -1) continue;
            parent[child] = node;
            q.push(child);
         }
      }
      return parent[sink] != -1;
   };

   ll flow = 0;
   while(reachable()) {
      int node = sink;
      ll currFlow = LLONG_MAX;
      while(node != source) {
         currFlow = min(currFlow, capacity[parent[node]][node]);
         node = parent[node];
      }
      node = sink;
      while(node != source) {
         capacity[parent[node]][node] -= currFlow;
         capacity[node][parent[node]] += currFlow;
         node = parent[node];
      }
      flow += currFlow;
      fill(parent.begin(), parent.end(), -1);
   }  
   return flow;
}

signed main(){FUN;
  
   int n, m;
   cin >> n >> m;

   fore(i, 0, m) {
      int a, b, c;
      cin >> a >> b >> c;      
      adj[a].pb(b);
      adj[b].pb(a);
      capacity[a][b] += c;
   }

   cout << maxFlow(1, n) << endl;

   re0;
}