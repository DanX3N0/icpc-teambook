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

const int MOD = 1e9 + 7;

vi dp(5005);
vvi trie(1e6 + 5, vi(26));
vector<bool> isEndOfWord(1e6 + 5);
int trieNodeCount = 0;

void insertWordInTrie(string& word) {
  int currentNode = 0;
  for(char& c: word) {
    if(!trie[currentNode][c - 'a']) {
      trie[currentNode][c - 'a'] = ++trieNodeCount;
    }
    currentNode = trie[currentNode][c - 'a'];
  }
  isEndOfWord[currentNode] = true;
}

int countWays(int start, string& s) {
  int currentNode = 0;
  int ways = 0;
  fore(i,start, s.size()) {
    if(!trie[currentNode][s.at(i) - 'a']) return ways;
    currentNode = trie[currentNode][s[i] - 'a'];
    if(isEndOfWord[currentNode]) ways = (ways + dp[i + 1]) % MOD;
  }
  return ways;
}

signed main(){FUN;
  
  string s;
  cin >> s;
  int n;
  cin >> n;
  vector<string> vs(n);

  fore(i,0,n) {
    string data;
    cin >> data;
    vs[i] = data;
  }

  fore(i,0,n) {
    insertWordInTrie(vs[i]);
  }

  dp[s.size()] = 1;

  rofe(i, s.size()-1, 0) {
    dp[i] = countWays(i, s);
  }

  cout << dp[0] << endl;

  return 0;
}