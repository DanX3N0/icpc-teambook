#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FUN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define clr(a,h) memset(a,(h),sizeof(a))
#define f first
#define s second
#define pb push_back
#define fore(i, a, b) for (int i = (int) a, o_o = b; i < (int) o_o; ++i)
#define rofe(i, b, a) for (int i = (int) b, o_o = a; i >= (int) o_o; --i)
#define sz(x) (int) x.size()
#define endl '\n'
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
//const int INF = numeric_limits<int>::max()/4;
//const double PI = acos(-1);

int ans = 0;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int vis[1010][1010]; 
char g[1010][1010];

bool isNumber(char c) {
  if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') return true;
  return false;
}

void dfs(int i, int j, int n, int m) {
  vis[i][j] = 1;
  if (isNumber(g[i][j])) ans += (g[i][j] - '0');
  fore(k, 0, 4) {
    int row = i + dx[k];
    int col = j + dy[k];
    if (row >= 0 && row < n && col >= 0 && col < m) {
      if (g[row][col] == 'T') {
        vis[row][col] = 1;
        return;
      }
    }
  }

  fore(k, 0, 4) {
    int row = i + dx[k];
    int col = j + dy[k];
    if (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] == 0 && (isNumber(g[row][col]) || g[row][col] == '.')) {
      dfs(row, col, n, m);
    }
  }
  return;
}

signed main() {
  FUN;
  int n, m;
  while (cin >> n >> m) {
    memset(vis, 0, sizeof(vis));
    memset(g, 0, sizeof(g));
    ii start;
    fore(i, 0, n) fore(j, 0, m) {
      cin >> g[i][j];
      if (g[i][j] == 'S') start = {i, j};
      if (g[i][j] == 'T' || g[i][j] == '#') vis[i][j] = 1;
    }
    ans = 0;
    dfs(start.f, start.s, n, m);
    memset(g, 0, sizeof(g));
    memset(vis, 0, sizeof(vis));
    cout << ans << endl;
  }

  return 0;
}