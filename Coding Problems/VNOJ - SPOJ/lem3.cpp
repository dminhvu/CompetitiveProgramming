#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int inf = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<vector<int> > a(n, vector<int>(n, 0));
    rep(i,n) {
        rep(j,n) {
            cin >> a[i][j];
        }
    }
    int ans = inf;
    vector<vector<int> > dp(n, vector<int>(1 << n, inf));
    queue<tuple<int, int, int> > q;
    rep(i,n) {
        dp[i][1 << i] = 0;
        q.push({i, 1 << i, 0});
    }
    while (q.size()) {
        int u = get<0>(q.front());
        int bit_string = get<1>(q.front());
        int cost = get<2>(q.front());
        // cout << bit_string << '\n';
        q.pop();
        for (int j = 0; j < n; j++) {
            if ((bit_string >> j) & 1) {
                continue;
            }
            if (dp[j][bit_string | (1 << j)] > cost + a[u][j]) {
                dp[j][bit_string | (1 << j)] = cost + a[u][j];
                q.push({j, (bit_string | (1 << j)), cost + a[u][j]});
            }
        }
    }
    rep(i,n) ans = min(ans, dp[i][(1 << n) - 1]);
    cout << ans << '\n';
    return 0;
}