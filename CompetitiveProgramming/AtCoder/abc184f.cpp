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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; ll t; cin >> n >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b{0}, c{0};
    rep(i,n) {
        ford(j,sz(b)-1,0) b.pb(b[j] + a[i]);
        swap(b, c);
    }
    sort(b.begin(),b.end(),greater<ll>());
    ll ans = 0;
    rep(i,sz(c)) {
        if (c[i] > t) continue;
        maxi(ans, c[i] + *lower_bound(b.begin(), b.end(), t - c[i], greater<ll>()));
    }
    cout << ans;
    return 0;
}