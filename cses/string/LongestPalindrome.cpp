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

//manacher's algorithm O(n)
int oddLength[1000007], evenLength[1000007];

string solve(string& s, int n)
{

    // Find the lengths of the longest odd-length
    // palindromic substrings centered at each index
    for (int i = 0, left = 0, right = -1; i < n; i++) {

        // Initialize the length as 1 if the current index
        // is beyond the right boundary
        int length = (i > right)
                         ? 1
                         : min(oddLength[left + right - i],
                               right - i + 1);

        // Expand around the center to find the longest
        // palindrome
        while (0 <= i - length && i + length < n
               && s[i - length] == s[i + length]) {
            length++;
        }

        // Update the length of the longest odd-length
        // palindrome centered at index i
        oddLength[i] = length--;

        // Update the boundaries of the current palindrome
        if (i + length > right) {
            left = i - length;
            right = i + length;
        }
    }

    // Find the lengths of the longest even-length
    // palindromic substrings centered at each index
    for (int i = 0, left = 0, right = -1; i < n; i++) {

        // Initialize the length as 0 if the current index
        // is beyond the right boundary
        int length
            = (i > right)
                  ? 0
                  : min(evenLength[left + right - i + 1],
                        right - i + 1);

        // Expand around the center to find the longest
        // palindrome
        while (0 <= i - length - 1 && i + length < n
               && s[i - length - 1] == s[i + length]) {
            length++;
        }

        // Update the length of the longest even-length
        // palindrome centered at index i
        evenLength[i] = length--;

        // Update the boundaries of the current palindrome
        if (i + length > right) {
            left = i - length - 1;
            right = i + length;
        }
    }

    // Find the longest palindromic substring
    int maxLength = 0, center = -1;
    for (int i = 0; i < n; i++) {

        // Update the maxLength and center if a longer
        // palindrome is found
        if (oddLength[i] * 2 - 1 > maxLength) {
            maxLength = oddLength[i] * 2 - 1;
            center = i;
        }
        if (evenLength[i] * 2 > maxLength) {
            maxLength = evenLength[i] * 2;
            center = i;
        }
    }

    // Return the longest palindromic substring
    if (maxLength % 2 == 1)
        return s.substr(center - maxLength / 2, maxLength);
    return s.substr(center - maxLength / 2, maxLength);
}

signed main(){FUN;
  
   string s;
   cin >> s;

   int n = s.size();

   cout << solve(s, n) << endl;

   re0;
}