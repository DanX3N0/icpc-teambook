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
#define INF64 ((ll) 1 << 60)
#define INF32 (1 << 30)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

const int INF = numeric_limits<int>::max()/4;
const double PI = acos(-1);

struct MinSegmentTree
{
  struct Node
  {
    ll l, r, val;
    Node *next_left;
    Node *next_right;

    ll get_left() { return (l + r) / 2; }
    ll get_right() { return get_left() + 1; }
  };

  Node *root = new Node();
  vector<ll> &arr;

  MinSegmentTree(vector<ll> &a) : arr(a)
  {
    root->l = 0;
    root->r = a.size() - 1;
    build_tree(root);
  }

  void build_tree(Node *node)
  {
    if (node->l == node->r)
    {
      node->val = arr[node->l];
      return;
    }

    node->next_left = new Node();
    node->next_left->l = node->l;
    node->next_left->r = node->get_left();
    build_tree(node->next_left);

    node->next_right = new Node();
    node->next_right->l = node->get_right();
    node->next_right->r = node->r;
    build_tree(node->next_right);

    node->val = min(node->next_left->val, node->next_right->val);
  }

  ll _get(ll l, ll r, Node *node)
  {
    if (node->l == l && node->r == r)
      return node->val;

    ll r1 = (l <= node->get_left() ? _get(l, min(node->get_left(), r), node->next_left) : INF64);
    ll r2 = (r >= node->get_right() ? _get(max(node->get_right(), l), r, node->next_right) : INF64);
    return min(r1, r2);
  }

  ll get(ll l, ll r)
  {
    return _get(l, r, root);
  }
};

vll a;

signed main(){FUN;
  
  int n,q;
  cin>>n>>q;
  a.resize(n);
  fore(i,0,n) cin>>a[i];
  
  MinSegmentTree st(a);

  while(q--){
    int l,r;
    cin>>l>>r;
    l--;r--;
    cout<<st.get(l,r)<<endl;
  }

  return 0;
}