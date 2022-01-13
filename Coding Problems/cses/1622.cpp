#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

set<string> ans;

void solve(int n, string s, int checknum, string cur) {
    if (cur.size() == n) {
        ans.insert(cur);
        return;
    }
    rep(i,n) {
        if ((checknum >> i) & 1) {
            continue;
        }
        solve(n, s, checknum | (1 << i), cur + s[i]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    solve(n, s, 0, "");
    cout << ans.size() << '\n';
    for (auto it: ans) cout << it << '\n';
    return 0;
}