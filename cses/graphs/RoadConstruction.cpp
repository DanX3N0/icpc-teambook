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
int p[tam], _rank[tam];
int nodes;

int findParent(int v) {
   if(p[v] == -1) return v;
   return p[v] = findParent(p[v]);
}

void join(int a, int b) {
   a = findParent(a);
   b = findParent(b);
   if(a == b) return;
   
   nodes--;
   if(_rank[a] > _rank[b]) {
      p[b] = a;
      _rank[a] += _rank[b];
      _rank[b] = _rank[a];
   } else {
      p[a] = b;
      _rank[b] += _rank[a];
      _rank[a] = _rank[b];
   }
}

signed main(){FUN;
   
   fore(i, 0, tam) p[i] = -1;
   fore(i, 0, tam) _rank[i] = 1;
   
   int n, m;
   cin >> n >> m;


   nodes = n;
   int maxNodes = 1;

   fore(i, 0, m) {
      int a, b;
      cin >> a >> b;
      join(a, b);
      maxNodes = max(maxNodes, _rank[findParent(a)]);
      cout << nodes << " " << maxNodes << endl;
   }

   re0;
}