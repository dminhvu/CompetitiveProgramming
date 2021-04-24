#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define fore(i,a,b) for (int i = (a); i <= (b); i++)
#define ford(i,a,b) for (int i = (a); i >= (b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<int, int> > v;
    rep(i,k) {
        int l, r; cin >> l >> r;
        r++;
        v.push_back({l, r});
    }
    vector<ll> dp(n);
    dp[0] = 1;
    dp[1] = -1;
    rep(i,n) {
        if (i > 0) dp[i] = (dp[i] % mod + dp[i - 1] % mod) % mod;
        rep(j,k) {
            if (i + v[j].fi < n) dp[i + v[j].fi] = (dp[i + v[j].fi] % mod + dp[i] % mod + mod * mod) % mod;
            if (i + v[j].se < n) dp[i + v[j].se] = (dp[i + v[j].se] % mod - dp[i] % mod + mod * mod) % mod;
        }
    }
    cout << dp[n - 1];
    return 0;
}