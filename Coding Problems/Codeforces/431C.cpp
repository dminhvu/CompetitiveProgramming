#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 1e2 + 5;
const ll mod = 1e9 + 7;

ll dp[N];

ll calc(int n, bool f) {
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];
    int init = (f ? 1 : 2);
    dp[n] = 0;
    for(int i = init; i <= k; i++) dp[n] = (dp[n][k] % mod + calc(n - init, f | (i >= d)) % mod) % mod;
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    memset(dp,-1,sizeof dp);
    dp[0][0] = 1;
    return 0;
}