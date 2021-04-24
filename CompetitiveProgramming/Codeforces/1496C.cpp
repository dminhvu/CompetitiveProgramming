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
using ld = long double;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<ll> > v(2);
        rep(i,2*n) {
            ll x, y; cin >> x >> y;
            if (x == 0) v[0].push_back(abs(y));
            else v[1].push_back(abs(x));
        }
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        ld ans = 0;
        rep(i,n) {
            ans += sqrt(ld(ld(v[0][i] * v[0][i]) + ld(v[1][i] * v[1][i])));
        }
        cout << fixed << setprecision(15) << ans << '\n';
    }
    return 0;
}