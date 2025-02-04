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
    int t; cin >> t;
    while (t--) {
        int n, k1, k2, w, b; cin >> n >> k1 >> k2 >> w >> b;
        w -= min(k1, k2);
        b -= min(n - k1, n - k2);
        int mn1 = min(k1, k2);
        k1 -= mn1;
        k2 -= mn1;
        int mn2 = min(n - k1, n - k2);
        int nk1 = n - k1, nk2 = n - k2;
        nk1 -= mn2;
        nk2 -= mn2;
        w -= k1 / 2;
        w -= k2 / 2;
        b -= nk1 / 2;
        b -= nk2 / 2;
        if (w <= 0 && b <= 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}