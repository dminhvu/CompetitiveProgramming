#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int N = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<ll> a(N, 0);
    vector<ll> dp(N, 0);
    a[1] = 1;
    dp[1] = 1;
    rep(i,N) {
        if (i < 2) continue;
        dp[i] = max(dp[i], dp[i - 1]);
        if (i % 2 == 0) {
            a[i] = a[i / 2];
        } else {
            a[i] = a[(i - 1)/2] + a[(i - 1)/2 + 1];
        }
        dp[i] = max(dp[i], a[i]);
    }
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}