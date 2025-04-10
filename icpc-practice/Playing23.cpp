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

signed main(){FUN;
   
   vi cards(14, 0);

   int rounds;
   cin >> rounds;

   int a, b;
   int sumJhon = 0, sumMary = 0;

   cin >> a >> b;
   cards[a]++;
   cards[b]++;
   if(a >= 10) sumJhon += 10;
   else sumJhon += a;
   if(b >= 10) sumJhon += 10;
   else sumJhon += b;
   
   cin >> a >> b;
   if(a >= 10) sumMary += 10;
   else sumMary += a;
   if(b >= 10) sumMary += 10;
   else sumMary += b;
   cards[a]++;
   cards[b]++;

   int sumCommon = 0;

   fore(i, 0, rounds) {
      int x;
      cin >> x;
      cards[x]++;
      if(x >= 10) sumCommon += 10;
      else sumCommon += x;
   }

   if(sumCommon >= 23) {
      cout << -1 << endl;
   } else {
      sumJhon += sumCommon;
      sumMary += sumCommon;
      if(sumJhon >= 23 && sumMary >= 23) {
         cout << -1 << endl;
         exit(0);
      }
      int d1 = abs(sumJhon - 23);
      int d2 = abs(sumMary - 23);
      int d = min(d1, d2);
      int ans = -1;
      fore(i, d, 14) {
         if(cards[i] >= 4 || i == 0) continue;
         int val1, val2;
         if(i >= 10) {
            val1 = sumJhon + 10;
            val2 = sumMary + 10;
         }
         else {
            val1 = sumJhon + i;
            val2 = sumMary + i;
         }
         
         if(val2 == 23) {
            ans = i;
            break;
         }

         if(val1 > 23 && val2 < 23) {
            ans = i;
            break;
         }
      }
      if(ans >= 10) cout << 10 << endl;
      else cout << ans << endl;
   }

   re0;
}