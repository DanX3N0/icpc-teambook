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

const int MAX_N = 100005;

vvi graph(MAX_N);
vi vis(MAX_N, 0);
vii dist(MAX_N, {INT_MAX,0});// w , p

signed main(){FUN;
  
  int n,m;
  cin>>n>>m;

  fore(i,0,m) {
    int a,b;
    cin>>a>>b;
    graph[a].pb(b);
    graph[b].pb(a);
  }

  queue<pair<int,ii>> q;//node w parent

  int node = 1;
  q.push({node,{0, 0}});
  dist[node] = {0,0};

  while(!q.empty()) {
    int node = q.front().f;
    int w = q.front().s.f;
    int parent = q.front().s.s;
    q.pop();
    
    if(!vis[node]) {

      vis[node] = 1;
      if(dist[node].f > w) {
        dist[node].f = w;
        dist[node].s = parent;
      }

      for(auto it: graph[node]) {
        if(!vis[it]) {
          q.push({it, {w+1, node}});
        }
      }

    }

    
  }

  vi ans;
  int src = n;
  ans.pb(src);
  while(src != 1) {
    if(dist[src].s == 0) {
      cout << "IMPOSSIBLE" << endl;
      exit(0);
    } else {
      ans.pb(dist[src].s);
      src = dist[src].s;
    }
  }

  cout << sz(ans) << endl;
  rofe(i, sz(ans)-1, 0) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}