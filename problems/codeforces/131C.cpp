#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

ll dp[100][100];

ll C(int k, int n) {
    if (dp[k][n] != -1) return dp[k][n];
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    return dp[k][n] = C(k - 1, n - 1) + C(k, n - 1);
}

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    memset(dp,255,sizeof dp);
    int n, m, t; cin >> n >> m >> t;
    ll ans = 0;
    fore(i,4,t) {
        int number_of_boys = i;
        int number_of_girls = t - i;
        if (number_of_girls < 1) continue;
        if (number_of_boys > n) continue;
        if (number_of_girls > m) continue;
        ans += C(number_of_boys, n) * C(number_of_girls, m);
    }
    cout << ans << '\n';
    return 0;
}