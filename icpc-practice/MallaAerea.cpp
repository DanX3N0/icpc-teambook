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

signed main(){FUN;
   
   int n;
   cin >> n;

   vvi matrix(n, vi(n));

   fore(i, 0, n) fore(j, 0, n) cin >> matrix[i][j];

   vvi floyd = matrix;

   // fore(i, 0, n) {
   //    fore(j, 0, n) {
   //       cout << matrix[i][j] << ' ';
   //    }
   //    cout << endl;
   //}

   int ans = 0;
   //FLOYD - W
   fore(k,0,n) fore(i,0,n) fore(j,0,n) floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]); 

   // fore(k, 0, n) {
   //    fore(i, 0, n) {
   //       fore(j, 0, n) {
   //          if((matrix[i][k] + matrix[k][j] == matrix[i][j]) && (matrix[i][j] > 0 && matrix[i][k] > 0 && matrix[k][j] > 0)) {
   //             //cout << "->" << matrix[i][k] << " " << matrix[k][j] << " " <<matrix[i][j] << endl;
   //             ans++;
   //          } else if((matrix[i][k] + matrix[k][j] < matrix[i][j]) && (matrix[i][j] > 0 && matrix[i][k] > 0 && matrix[k][j] > 0)) {
   //             cout << -1 << endl;
   //             exit(0);
   //          }
   //       }
   //    }
   // }

   int diff = 0;

   fore(i,0,n){
      fore(j,0,n){
         if(floyd[i][j] != matrix[i][j]) diff++;
      }
   }

   if(diff > 0) {
      cout << -1 << endl;
   } else {

      fore(k,0,n) fore(i,0,n) fore(j,0,n) if(floyd[i][k] + floyd[k][j] == floyd[i][j] && floyd[i][j] > 0 && floyd[i][k] > 0 && floyd[k][j] > 0) {
         ans++;
         floyd[i][j] = 0;
      } 

      ans /= 2;
      cout << ans << endl;
   }

   re0;
}