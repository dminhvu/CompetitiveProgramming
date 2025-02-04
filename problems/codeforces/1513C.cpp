#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int mod = 1e9 + 7;
const int maxn = 2e5 + 20;

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> dp(10, 0);
    dp[9] = 1;
    vector<int> v; // v[i] = length of the acquired number if apply i operations on number 0
    rep(i,10) v.push_back(1ll);
    rep(i,maxn) {
        if (i < 10) continue;
        vector<int> tmp = dp;
        fore(j,1,9) tmp[j] = dp[j - 1];
        tmp[0] = dp[9];
        tmp[1] += dp[9];
        fore(j,0,9) tmp[j] %= mod;
        dp = tmp;
        int sum = 0;
        rep(j,10) sum = (sum % mod + dp[j] % mod) % mod;
        v.push_back(sum);
    }
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, m; cin >> n >> m;
        string s = to_string(n);
        int ans = 0;
        rep(i,sz(s)) {
            ans = (ans % mod + v[m + int(s[i] - '0')] % mod) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}