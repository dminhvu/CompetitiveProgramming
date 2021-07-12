#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll mod = 1e9 + 7;

int main() {
    freopen64("input.txt","r",stdin);
    freopen64("output.txt","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll cnt = 0;
    for(int i = 1600; i <= 1700; i+=2) {
        int ans = 2;
        while (i % ans == 0) ans += 1;
        cnt += ans;
        cout << i << " " << ans << " " << cnt << '\n';
    }
    // int nTest; cin >> nTest;
    // while (nTest--) {
    //     ll n; cin >> n;
    //     ll ans = 0;
    //     ll odd = (n - 1) / 2ll + 1;
    //     ans += (2ll * odd) % mod;
    //     ll even = (n - 2) / 2ll + 1;
    //     if (n == 1) even = 0;
    //     ans += 3ll * even;
    //     ans += mod;
    //     ans %= mod;

    //     ll fact = 6;
    //     ll p = 2;
    //     while (fact <= n) {
    //         ll cnt = (n - fact) / fact + 1;
    //         ans += 2ll * cnt;
    //         ans += mod;
    //         ans %= mod;
    //         fact *= p;
    //         p++;
    //     }
    //     cout << ans << '\n';
    // }
    return 0;
}