#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    s = ' ' + s;
    vector<vector<int>> cnt(n + 1, vector<int>(26, 0));
    fore(i,1,n) {
        rep(j,26) {
            cnt[i][j] = cnt[i - 1][j] + (s[i] - 'a' == j);
        }
    }
    while (q--) {
        int l, r; cin >> l >> r;
        ll ans = 0;
        rep(i,26) {
            ans += 1ll * (cnt[r][i] - cnt[l - 1][i]) * (i + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}