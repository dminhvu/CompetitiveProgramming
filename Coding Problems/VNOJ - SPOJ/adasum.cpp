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

int binpow(int n, int k) {
    if (k == 0) return 1;
    int tmp = binpow(n, k / 2);
    tmp = 1ll * tmp * tmp % mod;
    if (k & 1) tmp = 1ll * tmp * n % mod;
    return tmp;
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = sz(s);
    vector<vector<int> > sum(10, vector<int>(n + 1, 0));
    sum[1][0] = 1;
    rep(j,n+1) {
        if (j == 0) continue;
        sum[1][j] = (10ll * sum[1][j - 1] + 1ll) % mod;
    }
    rep(i,10) {
        if (i < 2) continue;
        sum[i][0] = i;
        rep(j,n+1) {
            if (j < 1) continue;
            sum[i][j] = (10ll * sum[i][j - 1] + 1ll * i) % mod;
        }
    }
    int ans = 0;
    rep(i,n) {
        ans = (1ll * ans + 1ll * (i + 1) * sum[s[i] - '0'][n - i - 1]) % mod;
    }
    cout << ans << '\n';
    return 0;
}