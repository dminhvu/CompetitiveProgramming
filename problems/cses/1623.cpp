#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll inf = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    rep(i,n) sum += 1ll * a[i];
    ll ans = inf;
    rep(i,(1<<n)) {
        ll cur = 0;
        rep(j,n) {
            if ((i >> j) & 1) {
                cur += 1ll * a[j];
            }
        }
        ll diff = llabs(sum - 2ll * cur);
        ans = min(ans, diff);
    }
    cout << ans << '\n';
    return 0;
}