#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

ll dp[105][105];

ll C(int k, int n) {
    if (n < k) return 0;
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    if (dp[k][n] != -1) return dp[k][n];
    return dp[k][n] = C(k - 1, n - 1) + C(k, n - 1);
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp,255,sizeof dp);
    int n, m; cin >> n >> m;
    vector<vector<int> > a(n + 1, vector<int>(m + 1));
    rep(i,n) rep(j,m) cin >> a[i + 1][j + 1];
    vector<int> row(n + 1, 0), col(m + 1, 0);
    rep(i,n) {
        rep(j,m) {
            row[i + 1] += a[i + 1][j + 1];
        }
    }
    rep(j,m) {
        rep(i,n) {
            col[j + 1] += a[i + 1][j + 1];
        }
    }
    ll ans = 0;
    rep(i,n) {
        fore(j,1,row[i + 1]) {
            ans += C(j, row[i + 1]);
        }
        fore(j,1,m - row[i + 1]) {
            ans += C(j, m - row[i + 1]);
        }
    }
    rep(i,m) {
        fore(j,2,col[i + 1]) {
            ans += C(j, col[i + 1]);
        }
        fore(j,2,n - col[i + 1]) {
            ans += C(j, n - col[i + 1]);
        }
    }
    cout << ans << '\n';
    return 0;
}