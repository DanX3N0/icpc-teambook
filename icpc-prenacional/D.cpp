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

const int MAX_N = 100001;
bool criba[MAX_N];
vi primes(MAX_N, 0);

ll sumDiv(ll n) {
  ll pf_idx = 0, pf = primes[pf_idx], ans = 1;
  while (pf * pf <= n) {
    ll power = 0;
    while (n % pf == 0) {n /= pf; power++;}
    ans *= ((ll)pow((double)pf, power + 1.0) - 1) / (pf - 1);
    pf = primes[++pf_idx];
  }
  if (n != 1) ans *= ((ll)pow((double)n, 2.0) - 1) / (n - 1);
  return ans;
}


signed main() {
  FUN;

  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  memset(criba, true, sizeof criba);

  criba[0] = criba[1] = false;
  for (int i = 2; i <= MAX_N; i++) {
    if (criba[i] && (long long)i * i <= MAX_N) {
      for (int j = i * i; j <= MAX_N; j += i)
        criba[j] = false;
    }
  }
  int idx = 0;
  fore(i, 2, MAX_N) if (criba[i]) primes[idx++] = i;

  int t; cin >> t;
  fore(i, 0, t) {
    int n; cin >> n;
    int sum = sumDiv(n) - n;
    bool p = false, r = false, a = false;
    if (sum == n) p = true;
    if (sum > n) a = true;
    int otherSum;
    if (n == 1) otherSum = 0;
    else otherSum = sumDiv(sum) - sum;
    if (otherSum == n) r = true;
    if (!p && !r && !a) {
      cout << n << " complicado" << endl;
    } else {
      if (p) {
        cout << n << " perfecto" << endl;
      } else {
        if (r && a) {
          cout << n << " romantico abundante" << endl;
        } else {
          if (r) cout << n << " romantico" << endl;
          else if (a) cout << n << " abundante" << endl;
        }
      }
    }
  }

  return 0;
}