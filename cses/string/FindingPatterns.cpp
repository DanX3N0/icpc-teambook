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

//AHO CORASICK

const int MAX = 6e5 + 7;
const int SIGMA = 26;
int n;
string s;

//n in trie
int nodes = 1;
int trie[MAX][SIGMA];
int fail[MAX];  // fail[u] = the failure link for node
int seen[MAX];  // check if a node has been visited in trie
int ans[MAX];   // ans[i] = the number of occurrences of word i

//leaf[node] stores the idx of the word in node
vi leaf[MAX];
vi g[MAX];

/** Add a word to the trie */
void add_word(const string &word, const int &idx) {
	int node = 1;
	for (char ch : word) {
		if (trie[node][ch - 'a'] == 0) { trie[node][ch - 'a'] = ++nodes; }
		node = trie[node][ch - 'a'];
	}
	leaf[node].pb(idx);
}

/** BFS to building the failure and suffix links */
void build() {
	queue<int> q;
	int node = 1;
	fail[node] = 1;
	for (int i = 0; i < SIGMA; i++) {
		if (trie[node][i]) {
			fail[trie[node][i]] = node;
			q.push(trie[node][i]);
		} else {
			trie[node][i] = 1;
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < SIGMA; i++) {
			if (trie[node][i]) {
				fail[trie[node][i]] = trie[fail[node]][i];
				q.push(trie[node][i]);
			} else {
				trie[node][i] = trie[fail[node]][i];
			}
		}
	}
	for (int i = 2; i <= nodes; i++) { g[fail[i]].push_back(i); }
}

void search() {
	int node = 1;
	for (char ch : s) {
		node = trie[node][ch - 'a'];
		seen[node]++;
	}
}

int dfs(int node) {
	int sol = seen[node];
	for (int son : g[node]) { sol += dfs(son); }
	for (int idx : leaf[node]) { ans[idx] = sol; }
	return sol;
}

signed main(){FUN;
  
   cin >> s >> n;

	fore(i, 0, n) {
		string word;
		cin >> word;
		add_word(word, i);
	}

	build();
	search();
	dfs(1);

	fore(i, 0, n) cout << (ans[i] ? "YES" : "NO") << endl;

   re0;
}