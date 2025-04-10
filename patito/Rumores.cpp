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

const int tam = 107;

int p[tam], _rank[tam];

int findParent(int v) {
   if(p[v] == -1) return v;
   return p[v] = findParent(p[v]);
}

void join(int a, int b) {

   a = findParent(a);
   b = findParent(b);

   if(a == b) return;

   if(_rank[a] > _rank[b]) {
      p[b] = a;
      _rank[a] = max(_rank[a] + 1, _rank[b] + 1);
   } else {
      p[a] = b;
      _rank[b] = max(_rank[a] + 1, _rank[b] + 1);
   }

}

signed main(){FUN;
  
   int t;
   cin >> t;

   while(t--) {

      clr(p, -1);
      clr(_rank, 0);

      int n, m;
      cin >> n >> m;

      fore(i,0,m) {
         int u, v;
         cin >> u >> v;
         join(u, v);
      } 

      int x, y;
      cin >> x >> y;

      if(findParent(x) == findParent(y)) cout << "SI" << endl;
      else cout << "NO" << endl;

   }
 
   re0;
}