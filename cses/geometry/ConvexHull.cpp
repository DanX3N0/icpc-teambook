#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FUN                      \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);                   \
   cout.tie(0);
#define int long long
#define re0 return 0
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define clr(a, h) memset(a, (h), sizeof(a))
#define f first
#define s second
#define fore(i, a, b) for (int i = (int)a, o_o = b; i < (int)o_o; ++i)
#define rofe(i, b, a) for (int i = (int)b, o_o = a; i >= (int)o_o; --i)
#define sz(x) (int)x.size()
#define endl '\n'
#define INF64 ((ll)1 << 60)
#define INF32 (1 << 30)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
// const int INF = numeric_limits<int>::max()/4;
// const double PI = acos(-1);
// const int MOD = 1000000007;

struct pt {
    double x, y;
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();

    a = st;
}

signed main() {FUN;

   int n;
   cin >> n;

   vector<pt> vpt;

   fore(i, 0, n) {
      int x, y;
      cin >> x >> y;
      pt p = {x, y};
      vpt.pb(p);
   }

   convex_hull(vpt, 1);

   cout << vpt.size() << endl;

   fore(i, 0, sz(vpt)) {
      cout << (int)vpt[i].x << " " << (int)vpt[i].y << endl;
   }

   re0;
}