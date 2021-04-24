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
        bool f = 1;
        rep(i,sz(s)) {
            f &= (s[i] == 'a');
        }
        if (!f) {
            cout << "YES\n";
            s.insert(0,"a");
            rep(i,sz(s)) {
                if (s[i] != s[sz(s) - i - 1]) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                cout << s << '\n';
                continue;
            }
            s.erase(0,1);
            s.insert(sz(s)-1,"a");
            rep(i,sz(s)) {
                if (s[i] != s[sz(s) - i - 1]) {
                    f = 1;
                    break;
                }
            }
            if (f) {
                cout << s << '\n';
                continue;
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}