#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}


vector<bool> row(8, false), diag1(16, false), diag2(16, false);
vector<vector<char> > a(8, vector<char>(8));

ll ans = 0;

void solve(int n, int cur_col) {
    if (cur_col == n) {
        ans += 1;
        return;
    }
    rep(i,n) {
        if (row[i] || diag1[i - cur_col + 8] || diag2[i + cur_col] || a[i][cur_col] == '*') {
            continue;
        }
        row[i] = true;
        diag1[i - cur_col + 8] = true;
        diag2[i + cur_col] = true;
        solve(n, cur_col + 1);
        row[i] = false;
        diag1[i - cur_col + 8] = false;
        diag2[i + cur_col] = false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    rep(i,8) {
        rep(j,8) {
            cin >> a[i][j];
        }
    }
    solve(8, 0);
    cout << ans << '\n';
    return 0;
}