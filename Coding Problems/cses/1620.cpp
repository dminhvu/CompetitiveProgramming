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
    int n; ll t; cin >> n >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll l = 0, r = 1e18 + 5;
    while (l <= r) {
        ll mid = (l + r) / 2ll;
        ll sum = 0;
        rep(i,n) {
            sum += mid / a[i];
            if (sum >= t) {
                break;
            }
        }
        if (sum >= t) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}