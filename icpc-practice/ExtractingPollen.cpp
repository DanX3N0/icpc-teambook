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

const int tam = 1e6 + 7;

vi steps(tam, -1);

int sumDig(int n) {
   if(n == 0) return 0;
   if(steps[n] != -1) return steps[n];
   int sum = 0;
   int tmp = n;
   while(tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
   }
   return steps[n] = sumDig(n-sum) + 1;
}

signed main(){FUN;

   // pre-processing
   fore(i, 1, tam) {
      sumDig(i);
   }

   //fore(i, 0, 20) cout << steps[i] << endl;
   //cout << steps[100] << endl;
   
   int n, k;
   cin >> n >> k;

   vi flowers(n);

   fore(i, 0, n) cin >> flowers[i];

   vi valueFlowers(n);
   
   fore(i, 0, n) {
      int value = flowers[i];
      valueFlowers[i] = steps[value];
   }

   sort(all(valueFlowers), greater<int>());

   //for(auto it: valueFlowers) cout << it << ' ';
   
   int pos = 0, idx = 0;

   while(pos < k) {
      if(pos + valueFlowers[idx] < k) {
         pos += valueFlowers[idx++];
      } else {
         break;
      } 
   }

   

   re0;
}