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
    freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n), b(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    sum *= 2ll;
    rep(i,n) {
        cout << sum << " ";
        ll x = 2ll * min(a[i], b[i]);
        ll y = a[i] - b[i];
        if (y < 0) y = 0;
        sum += y - x;
    }
    cout << sum << '\n';
    return 0;
}