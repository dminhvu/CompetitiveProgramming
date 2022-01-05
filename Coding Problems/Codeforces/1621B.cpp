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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        int l = inf, r = -inf;
        int posl = 0, posr = 0;
        int costl = inf, costr = inf;
        int maxlen = 0, costlen = inf;
        int ans = inf;
        rep(i,n) {
            int x, y, c; cin >> x >> y >> c;
            if (x < l) {
                l = x;
                costl = inf;
            }
            if (l == x) costl = min(costl, c);
            if (y > r) {
                r = y;
                costr = inf;
            }
            if (y == r) costr = min(costr, c);

            if (y - x + 1 > maxlen) {
                maxlen = r - l + 1;
                costlen = inf;
            }    
            if (y - x + 1 == maxlen) {
                costlen = min(costlen, c);
            }
            int ans = costl + costr;
            if (r - l + 1 == maxlen) ans = min(ans, costlen);
            cout << ans << '\n';
        }
    }
    return 0;
}