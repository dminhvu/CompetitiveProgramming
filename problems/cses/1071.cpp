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
    int T; cin >> T;
    while (T--) {
        int x, y; cin >> y >> x;
        int k = max(x, y);
        ll ans = k - 1;
        ans *= ans;
        ans += 1;
        if (k & 1) {
            int start_x = 1, start_y = k;
            if (start_x < x) {
                ans += x - start_x;
            }
            if (start_y > y) {
                ans += start_y - y;
            }
        } else {
            int start_x = k, start_y = 1;
            if (y > start_y) {
                ans += y - start_y;
            }
            if (x < start_x) {
                ans += start_x - x;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}