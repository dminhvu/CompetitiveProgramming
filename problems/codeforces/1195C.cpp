#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    rep(i,n) {
        dp[i + 1][0][0] = max({dp[i][0][1], dp[i][1][1], dp[i][0][0], dp[i][1][0]});
        dp[i + 1][1][0] = max({dp[i][0][1], dp[i][1][1], dp[i][0][0], dp[i][1][0]});
        dp[i + 1][0][1] = max({dp[i][0][0], dp[i][1][0], dp[i][1][1]}) + a[i];
        dp[i + 1][1][1] = max({dp[i][1][0], dp[i][0][0], dp[i][0][1]}) + b[i];
    }
    cout << max(*max_element(all(dp[n][0])), *max_element(all(dp[n][1]))) << '\n';
    return 0;
}