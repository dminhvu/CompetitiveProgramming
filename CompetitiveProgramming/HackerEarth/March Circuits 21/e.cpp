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
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> inv(n + 1, 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
    }
    ll ans = 0;
    fore(i,2,n) {
        ll cur = 1ll * i * (1ll * i - 1) / 2ll;
        ans = (ans % mod + cur % mod) % mod;
        // cout << mul << " " << inv[2] << " " << inv[i - 2] << '\n';
    }
    cout << ans;
    return 0;
}