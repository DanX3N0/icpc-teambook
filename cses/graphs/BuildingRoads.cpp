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

const int MAX_N = 100010;

vvi g(MAX_N);
vi vis(MAX_N, 0);
vi conn;

void dfs(int src) {
  vis[src] = 1;
  for(auto e: g[src]) {
    if(!vis[e]) dfs(e); 
  }
  return;
}

signed main(){FUN;
  int n,m;
  cin>>n>>m;

  fore(i,0,m) {
    int a,b;
    cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }

  fore(i,1,n+1) {
    if(!vis[i]) {
      conn.pb(i);
      dfs(i);
    }
  }

  cout<<conn.size()-1<<endl;

  fore(i,0,(conn.size()-1)) {
    cout<<conn[i]<<" "<<conn[i+1]<<endl;
  }

  return 0;
}