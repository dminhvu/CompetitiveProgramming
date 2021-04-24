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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        rep(i,n) cin >> a[i];
        a[n] = -a[n - 1];
        ll ans = 0;
        bool sign = (a[0] > 0);
        int val = (sign ? 0 : inf);
        rep(i,n+1) {
            if (a[i] > 0) {
                if (!sign) {
                    ans -= val;
                    val = 0;
                    sign = 1;
                }
                maxi(val, a[i]);
            } else {
                if (sign) {
                    ans += val;
                    val = inf;
                    sign = 0;
                }
                mini(val, abs(a[i]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}