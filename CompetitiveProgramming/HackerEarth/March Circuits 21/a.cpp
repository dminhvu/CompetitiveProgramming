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
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        int l = 0, r = 1e9;
        auto calc = [&] (int x) {
            int cnt = 0;
            rep(i,n) {
                int diff = abs(x - a[i]);
                cnt += diff % 2;
            }
            return cnt;
        };
        int ans = inf;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int lt = calc(mid - 1), rt = calc(mid);
            mini(ans, lt);
            mini(ans, rt);
            if (lt < rt) r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}