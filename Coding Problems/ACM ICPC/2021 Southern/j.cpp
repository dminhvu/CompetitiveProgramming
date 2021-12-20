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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    rep(i,n) {
        cin >> s[i];
    }
    int ans = 0;
    vector<vector<int> > left(n, vector<int>(m, 0));
    vector<vector<int> > right(n, vector<int>(m, 0));
    vector<vector<int> > top(n, vector<int>(m, 0));
    vector<vector<int> > bottom(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            left[i][j] = s[i][j] - '0';
            if (j > 0 && s[i][j] == '1') left[i][j] = left[i][j - 1] + 1;
            top[i][j] = s[i][j] - '0';
            if (i > 0 && s[i][j] == '1') top[i][j] = top[i - 1][j] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            right[i][j] = s[i][j] - '0';
            if (j < m - 1 && s[i][j] == '1') right[i][j] = right[i][j + 1] + 1;
            bottom[i][j] = s[i][j] - '0';
            if (i < n - 1 && s[i][j] == '1') bottom[i][j] = bottom[i + 1][j] + 1;
        }
    }
    int x = -1, y = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int len = min({top[i][j], bottom[i][j], left[i][j], right[i][j]});
            if (4 * (len - 1) + 1 > ans) {
                if (4 * (len - 1) + 1 == ans && x != -1 && i > x) {
                    continue;
                }
                if (4 * (len - 1) + 1 == ans && y != -1 && j > y) {
                    continue;
                }
                x = i + 1;
                y = j + 1;
                ans = 4 * (len - 1) + 1;
            }
        }
    }
    if (x == -1) {
        cout << -1;
        return 0;
    }
    cout << ans << '\n';
    cout << x << " " << y << '\n';
    return 0;
}