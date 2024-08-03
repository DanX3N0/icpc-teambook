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

bool comp(ii& a, ii& b) {
  return a.f < b.f;
}

signed main(){FUN;

  int n, x;
  cin >> n >> x;

  vii a(n);

  fore(i, 0, n) {
    int data; cin >> data;
    a[i] = {data, i + 1};
  }

  int ptr1 = 0, ptr2 = n - 1;

  sort(a.begin(), a.end(), comp);

  while(ptr1 < ptr2) {
    int sum = a[ptr1].f + a[ptr2].f;
    if(sum == x) {
      ///int idx1 = a[ptr1].s;
      //int idx2 = a[ptr2].s;
      cout << a[ptr2].s << " " << a[ptr1].s << endl;
      exit(0);
    } else if(sum > x) {
      ptr2--;
    } else {
      ptr1++;
    }
  }

  if(ptr1 >= ptr2) cout << "IMPOSSIBLE" << endl;

  return 0;
}