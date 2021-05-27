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
        int n; cin >> n;
        string s; cin >> s;
        string x = "1", y = "1";
        bool f = 0;
        rep(i,n) {
            if (i == 0) continue;
            if (s[i] == '0') {
                x += "0";
                y += "0";
            } else if (s[i] == '1') {
                if (f == 0) {
                    f = 1;
                    x += "1";
                    y += "0";
                } else {
                    x += "0";
                    y += "1";
                }
            } else {
                if (f == 0) {
                    x += "1";
                    y += "1";
                } else {
                    x += "0";
                    y += "2";
                }
            }
        }
        cout << x << '\n' << y << '\n';
    }
    return 0;
}