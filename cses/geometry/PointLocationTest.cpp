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
#define fore(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
#define forr(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
#define sz(x) (int) x.size()
#define endl '\n'
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = numeric_limits<int>::max()/4;
const double PI = acos(-1);
const double EPS = 1e-9;

struct point{

  double x,y;
  point(){x=y=0;}
  point(double _x, double _y):x(_x),y(_y) {}
  point operator +(point a) const {
    a.x+=x;
    a.y+=y;
    return a;
  }

  point operator -(point a) const {
    a.x-=x;
    a.y-=y;
    return a;
  }

  double dist(point a, point b){
    return hypot(a.x-b.x,a.y-b.y);
  }

  double operator ^(point a) {
    return x*a.y-a.x*y;
  }

};

void solve(){
  int x1,y1,x2,y2,x3,y3;
  cin>>x1>>y1>>x2>>y2>>x3>>y3;
  point p1 = point(x1,y1);
  point p2 = point(x2,y2);
  point p3 = point(x3,y3);

  p2 = p2 - p1;
  p3 = p3 - p1;

  double ar = p2 ^ p3;

  if(ar<0) cout << "RIGHT" << endl;
  else if(ar>0) cout << "LEFT" << endl;
  else cout << "TOUCH" << endl;

}


signed main(){FUN;
  
  int t;cin>>t;
  while(t--){
    solve();
  }

  return 0;
}