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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, l; cin >> n >> l;
    vector<int> a(n + 1);
    rep(i,n) cin >> a[i + 1];
    vector<int> dp(n + 1, l + 1);
    dp[0] = 0;
    fore(i,1,n) {
        int sum = 0;
        ford(j,i,1) {
            sum += a[j];
            if (l >= sum) dp[i] = min(dp[i], max(dp[j - 1], l - sum));
        }
    }
    cout << dp[n] << '\n';
    return 0;
}