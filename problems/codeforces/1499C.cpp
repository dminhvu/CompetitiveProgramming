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
const int inf = 1e9;

int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> c(n);
        rep(i,n) cin >> c[i];
        vector<ll> pref(n, 0);
        rep(i,n) {
            pref[i] = c[i];
            if (i > 1) pref[i] += pref[i - 2];
        }
        vector<ll> a, b;
        rep(i,n) {
            if (i & 1) b.push_back(c[i]);
            else a.push_back(c[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        ll ans = 1ll * inf * inf;
        rep(i,sz(a)) {
            int p = a[i];
            ll cur = 0;
            if (p > 0) cur += pref[p - 1];
            if (p > 1) cur += pref[p - 2];
            ans = min(ans, cur + (n - (p + 1) / 2ll) * p);
        }
        cout << ans << '\n';
    }
    return 0;
}