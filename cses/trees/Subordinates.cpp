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

const int tam = 2 * 1e5 + 7;

vi adj[tam];
vi subor(tam, 0);

void dfs(int node) {
  for(auto it: adj[node]) {
    dfs(it);
    subor[node] += subor[it] + 1;
  }
}

signed main(){FUN;

  int n;
  cin >> n;

  fore(i, 2, n + 1) {
    int p; 
    cin >> p;
    adj[p].pb(i);
  } 

  dfs(1);

  fore(i, 1, n + 1) cout << subor[i] << " ";
  cout << endl;

  return 0;
}