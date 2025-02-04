#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    vector<vector<int> > dp(19, vector<int> (N, 0));
    rep(i,19) {
        int cnt = 0;
        rep(j,N) {
            cnt += ((j >> i) & 1);
            dp[i][j] = cnt;
        }
    }
    while (nTest--) {
        int u, v; cin >> u >> v;
        int ans = 0;
        rep(i,19) ans = max(ans, dp[i][v] - dp[i][u - 1]);
        cout << v - u + 1 - ans << '\n';
    }
    return 0;
}