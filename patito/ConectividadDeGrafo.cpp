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

const int tam = 57;

vi g[tam];
vi vis(tam, 0);

void dfs(int v) {
   vis[v] = 1;

   for(auto it: g[v]) {
      if(!vis[it]) {
         dfs(it);
      }
   }

}

signed main(){FUN;
  
   int t;
   cin >> t;
 
   while(t--) {

      fore(i,0,sz(vis)) vis[i] = 0;
      fore(i,0,tam) g[i].clear();

      string eti;
      cin >> eti;
      cout << eti << endl;
      int n = (eti[0] - 'A') + 1;
      string line;

      while(1) {
         getline(cin, line);
         if(line.size() == 0) break;
         int u = (line[0] - 'A') + 1;
         int v = (line[1] - 'A') + 1;
         
         cout << line << endl;

         cout << u << ";;" << v << endl;  

         //g[u].pb(v);
         //g[v].pb(u);

      }

      // int ans = 0;


      // fore(i, 1, n + 1) {
      //    if(!vis[i]) {
      //       dfs(i);
      //       ans++;
      //    }
      // }

      // cout << ans << endl;
      // cout << endl;
   }

   re0;
}