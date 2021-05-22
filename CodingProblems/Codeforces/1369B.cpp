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
    freopen("input.txt","r",stdin);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool f = 1;
        rep(i,n) {
            if (i) f &= (s[i] >= s[i - 1]);
        }
        if (f) {
            cout << s << '\n';
            continue;
        }
        string ans = "";
        while (sz(s) && s[0] == '0') {
            ans += "0";
            s.erase(0, 1);
        }
        ans += "0";
        while (sz(s) && s[sz(s) - 1] == '1') {
            ans += "1";
            s.erase(sz(s) - 1, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}