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

vvii adj(tam);
vi vis(tam);
int visCont = 0;

signed main(){FUN;
  
   int n, m;
   cin >> n >> m;

   fore(i, 0, m) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].pb({b, c});
      adj[b].pb({a, c});
   }

   int ans = 0;

   priority_queue<ii, vii, greater<ii>> pq;
   pq.push({0, 1});
   
   while(!pq.empty()) {
      int dist = pq.top().f;
      int node = pq.top().s;
      pq.pop();
      if(!vis[node]) {
         vis[node] = 1;
         ans += dist;
         visCont++;
         for(auto it: adj[node]) {
            pq.push({it.s, it.f});
         }
      }
   }

   if(visCont == n) cout << ans << endl;
   else cout << "IMPOSSIBLE" << endl;

   re0;
}