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
    int n; ll k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    ll l = a[n / 2];
    ll r = int(4e9);
    while (l <= r) {
        ll mid = (l + r) >> 1ll;
        ll sum = k;
        for(int i = n/2; i < n; i++) {
            if (mid - a[i] >= 0) sum -= mid - a[i];
        }
        if (sum >= 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << '\n';
    return 0;
}