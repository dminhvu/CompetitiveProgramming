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
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<ll> a(n);
        rep(i,n) cin >> a[i];
        ll l = 1, r = 1e9 + 5;
        while (l <= r) {
            ll mid = (l + r) / 2ll;
            vector<ll> b = a;
            ford(i,n-1,2) {
                // a[i] - 3d >= mid
                // --> d <= (a[i] - mid)/3
                ll d = max(0ll, min(a[i]/3ll, (b[i] - mid)/3ll));
                b[i] -= 3ll * d;
                b[i - 2] += 2ll * d;
                b[i - 1] += d;
            }
            bool fine = true;
            rep(i,n) {
                fine &= (b[i] >= mid);
            }
            if (fine) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << r << '\n';
    }
    return 0;
}