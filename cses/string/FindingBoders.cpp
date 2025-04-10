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

const ll MOD = 1e9 + 7;
const ll prime1 = 31;
const ll prime2 = 37;
const int MAX = 1e6 + 5;

ll pow1[MAX], pow2[MAX], ph1, ph2, sh1, sh2;

void solve(string& s, int n) {
   
   //init powers p1 & p2
   pow1[0] = pow2[0] = 1;
   fore(i, 1, n) {
      pow1[i] = (pow1[i - 1] * prime1) % MOD;
      pow2[i] = (pow2[i - 1] * prime2) % MOD;
   }

   //calculate the preffix and suffix hashes
   fore(i, 0, n - 1) {
      int l = (s[i] - 'a' + 1);
      int r = (s[n - i - 1] - 'a' + 1);

      ph1 = (ph1 + l * pow1[i]) % MOD;
      ph2 = (ph2 + l * pow2[i]) % MOD;
      sh1 = (sh1 * prime1 + r) % MOD;
      sh2 = (sh2 * prime2 + r) % MOD;

      //if are equals, print the length of borders
      if(ph1 == sh1 && ph2 == sh2) cout << i + 1 << ' ';
   }

}

signed main(){FUN;
  
   string s;
   cin >> s;

   int n = s.size();

   solve(s, n);
   cout << endl;

   re0;
}