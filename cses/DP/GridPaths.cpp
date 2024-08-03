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

const int MOD = 1e9 + 7;
const int tam = 1007;

vvi dp(tam, vi(tam, 0));
char g[tam][tam];
int dx[] = {0, -1};
int dy[] = {-1, 0};

signed main(){FUN;
  
   int n;
   cin >> n;

   fore(i,0,n) {
      string line;
      cin >> line;
      fore(j, 0, n) {
         g[i][j] = line.at(j);
      }
   }
   dp[0][0] = 1;
   if(g[0][0] == '*') dp[0][0] = 0;

   fore(i, 0, n) {
      fore(j, 0, n) {
         if(g[i][j] == '.') {
            for(int k = 0; k < 2; k++) {
               int row = i + dy[k];
               int col = j + dx[k];
               if(row >= 0 && row < n && col >= 0 && col < n) {
                  //cout <<"->"<< row << "-"<<col<<endl;
                  dp[i][j] = (dp[row][col] + dp[i][j]) % MOD;
               }
            }            
         }
      }  
   }

   // fore(i,0,n) {
   //    fore(j,0,n){   
   //       cout << dp[i][j] << ' ';
   //    }
   //    cout << endl;
   // }

   cout << dp[n-1][n-1] << endl;

   return 0;
}