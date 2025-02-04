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
        string a, s; cin >> a >> s;
        int j = a.size() - 1;
        vector<char> b;
        bool found = true;
        for (int i = s.size() - 1; i >= 0; ) {
            if (j < 0) {
                b.push_back(s[i]);
                i -= 1;
                continue;
            }
            int curs = s[i] - '0';
            int cura = a[j] - '0';
            if (curs < cura) {
                if (i > 0) {
                    i -= 1;
                    curs = (s[i] - '0') * 10 + (s[i + 1] - '0');
                } else {
                    found = false;
                    break;
                }
            }
            if (curs - cura >= 0 && curs - cura <= 9) {
                b.push_back(curs - cura + '0');
                i -= 1;
                j -= 1;
            } else {
                found = false;
                break;
            }
        }
        if (!found || j >= 0) cout << -1 << '\n';
        else {
            reverse(b.begin(), b.end());
            ll ans = 0;
            for (char c: b) ans = ans * 10 + (c - '0');
            cout << ans << '\n';
        }
    }
    return 0;
}