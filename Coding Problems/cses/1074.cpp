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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    ll l = 1, r = *max_element(a.begin(), a.end());
    ll ans = 1e18;
    int N = 40;
    rep(i,N) {
        ll m0 = l + (r - l + 2) / 3ll;
        ll m1 = r - (r - l + 2) / 3ll;
        ll sum0 = 0, sum1 = 0;
        rep(i,n) {
            sum0 += llabs(m0 - a[i]);
            sum1 += llabs(m1 - a[i]);
        }
        ans = min({ans, sum0, sum1});
        if (sum0 < sum1) {
            r = m1;
        } else if (sum0 > sum1) {
            l = m0;
        } else {
            l = m0;
            r = m1;
        }
    }
    cout << ans;
    return 0;
}