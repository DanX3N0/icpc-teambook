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

int romanToArabic(string s) {
   map<char, int> mp;

   mp.insert({'I', 1});
   mp.insert({'V', 5});
   mp.insert({'X', 10});
   mp.insert({'L', 50});
   mp.insert({'C', 100});
   mp.insert({'D', 500});
   mp.insert({'M', 1000});

   char prevC = s[0];

   int ans = mp[prevC];

   fore(i,1,s.size()) {
      char c = s[i];
      if(c == prevC) {
         ans += mp[c];
      } else {
         if(mp[c] > mp[prevC] && mp[c] > ans) {
            ans = mp[c] - ans;
         } else if(ans < mp[c]){
            ans = mp[c] - ans;
         } else {
            ans += mp[c];
         }
      }
      prevC = c;

   }

   return ans;

}

signed main(){FUN;
  
   int n;
   cin >> n;

   while(n--) {
      string s;
      cin >> s;

      int ans = romanToArabic(s);

      cout << ans << endl;
      cout << "============" << endl;

   }

   re0;
}