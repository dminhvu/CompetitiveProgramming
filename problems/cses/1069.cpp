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
    string s; cin >> s;
    s = ' ' + s;
    int cur_len = 0, max_len = 0;
    rep(i,s.size()) {
        if (s[i + 1] == s[i]) cur_len += 1;
        else cur_len = 1;
        max_len = max(max_len, cur_len);
    }
    cout << max_len;
    return 0;
}