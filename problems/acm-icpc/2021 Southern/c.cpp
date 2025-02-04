#include<bits/stdc++.h>
#define rep(i,n) for (int i=0, _n=n; i<_n; i++)
#define FOR(i,a,b) for (int _a=(a), _b=(b), i=_a; _a<=_b?i<=_b:i>=_b; _a<=_b?i++:i--)
#define _mem(a, b) memset(a, (b), sizeof(a))
#define sz(a) int((a).size())

using namespace std;
typedef long long ll;
typedef int64_t i64;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
const int N = 2e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
const double pi = atan(1) * 4.0;
template<typename T, typename U> inline void mini(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void maxi(T &x, U y) { if(x < y) x = y; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    string s; cin >> s;
    int k; cin >> k;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        int pos = i;
        int k2 = k;
        string tmp = "";
        while (k2--) {
            if (pos > 0 && pos < s.size() - 1) {
                if (s[pos - 1] < s[pos + 1]) {
                    pos -= 1;
                } else {
                    pos += 1;
                }
            } else if (pos > 0) {
                pos -= 1;
            } else if (pos < s.size() - 1) {
                pos += 1;
            }
            tmp += s[pos];
        }
        if (ans == "") {
            ans = tmp;
        } else if (tmp < ans) {
            ans = tmp;
        }
    }
    cout << ans << '\n';
    return 0;
}