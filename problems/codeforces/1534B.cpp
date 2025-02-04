#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int inf = 1e9 + 5;

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n + 2, 0);
        fore(i,1,n) cin >> a[i];
        ll ans = 0;
        fore(i,1,n+1) {
            ans += 1ll * abs(a[i] - a[i - 1]);
        }
        fore(i,1,n) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                ll diff = 1ll * min(a[i] - a[i - 1], a[i] - a[i + 1]);
                ans -= diff;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}