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
        int l = inf, r = 0;
        int posl = -1, posr = -1;
        vector<tuple<int, int, int> > a;
        int ans = 0;
        rep(i,n) {
            int x, y, z; cin >> x >> y >> z;
            a.push_back({x, y, z});
            if (x < l) {
                if (posl != -1) {
                    ans -= get<2>(a[posl]);
                }
                ans += z;
                posl = i;
                l = x;
            } else if (x == l) {
                if (z < get<2>(a[posl])) {
                    posl = i;
                }
            }

            if (y > r) {
                if (posr != -1) {
                    ans -= get<2>(a[posr]);
                }
                ans += z;
                posr = i;
                r = y;
            } else if (y == r) {
                if (z < get<2>(a[posr])) {
                    posr = i;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}