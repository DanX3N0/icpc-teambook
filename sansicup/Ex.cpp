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
//const int MOD = 1000000007;

const int MAX_N = 100007;
bool criba[MAX_N];
vi primes(MAX_N, 0);

signed main(){FUN;

   fore(i,0,MAX_N) criba[i] = 1;

   criba[0] = criba[1] = false;
   for (int i = 2; i <= MAX_N; i++) {
      if (criba[i] && (ll)i * i <= MAX_N) {
         for (int j = i * i; j <= MAX_N; j += i)
         criba[j] = false;
      }
   }
   int idx = 0;
   fore(i, 2, MAX_N) if (criba[i]) primes[idx++] = i;


   int n; cin >> n;   

   unordered_map<ll, ll> umll;

   vll data(n);

   fore(i,0,n) cin >> data[i];

   fore(i,0,n) {

      ll number = data[i];

      if(umll.count(number) != 0) {
         cout << umll[number] << endl;
      } else {
         ll pf_idx = 0, pf = primes[pf_idx], ans = 1;
         while (pf * pf <= number) {
            ll power = 0;
            while (number % pf == 0) {number /= pf; power++;}
            ans *= ((ll)pow((double)pf, power + 1.0) - 1) / (pf - 1);
            pf = primes[++pf_idx];
         }
         if (number != 1) ans *= ((ll)pow((double)number, 2.0) - 1) / (number - 1);
         umll[number] = ans;
         cout << ans << endl;
      }   

   }


   re0;
}