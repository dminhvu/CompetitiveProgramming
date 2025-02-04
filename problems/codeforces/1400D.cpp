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
        string s; cin >> s;
        int x; cin >> x;
        int n = sz(s);
        s = ' ' + s;
        vector<int> ans(n + 1, 1);
        bool f = 1;
        fore(i,1,n) {
            if (s[i] == '1') continue;
            if (i > x) {
                ans[i - x] = 0;
            }
            if (i + x <= n) {
                ans[i + x] = 0;
            }
        }
        fore(i,1,n) {
            if (s[i] == '0') continue;
            bool tmp = 0;
            if (i > x) tmp |= ans[i - x] == 1;
            if (i + x <= n) tmp |= ans[i + x] == 1;
            f &= tmp;
        }
        if (!f) {
            cout << -1 << '\n';
            continue;
        }
        fore(i,1,n) cout << ans[i];
        cout << '\n';
    }
    return 0;
}