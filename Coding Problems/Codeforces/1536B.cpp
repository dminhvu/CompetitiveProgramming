#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

string inc(string s) {
    int n = sz(s) - 1;
    int r = 0;
    ford(i,n,0) {
        int c = s[i] - 'a';
        c += r;
        if (i == n) c++;
        if (c >= 26) {
            r = 1;
            c -= 26;
        } else {
            r = 0;
        }
        s[i] = c + 'a';
    }
    if (r) s.insert(s.begin(), 'a');
    return s;
}

int main() {
    freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        string s; cin >> s;
        set<string> st;
        fore(i,1,n) {
            string cur = "";
            rep(j,n) {
                cur += s[j];
                while (sz(cur) > i) cur.erase(0, sz(cur) - i);
                st.insert(cur);
            }
        }
        string ans = "a";
        while (st.count(ans)) {
            ans = inc(ans);
        }
        cout << ans << '\n';
    }
    return 0;
}