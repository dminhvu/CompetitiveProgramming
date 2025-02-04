#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

string s;
int n;
int ans = 0;
vector<vector<bool> > vis(7, vector<bool>(7, false));

void solve(int x, int y, int pos, char dir) {
    if (pos >= s.size()) {
        if (x == n - 1 && y == 0) {
            ans += 1;
        }
        return;
    }
    if (x == n - 1 && y == 0) return;
    if (dir == 'U' && (x == 0 || vis[x - 1][y]) && y > 0 && y < n - 1 && !vis[x][y - 1] && !vis[x][y + 1]) return;
    if (dir == 'D' && (x == n - 1 || vis[x + 1][y]) && y > 0 && y < n - 1 && !vis[x][y - 1] && !vis[x][y + 1]) return;
    if (dir == 'L' && (y == 0 || vis[x][y - 1]) && x > 0 && x < n - 1 && !vis[x - 1][y] && !vis[x + 1][y]) return;
    if (dir == 'R' && (y == n - 1 || vis[x][y + 1]) && x > 0 && x < n - 1 && !vis[x - 1][y] && !vis[x + 1][y]) return;
    vis[x][y] = true;
    if (s[pos] == '?') {
        if (x > 0 && !vis[x - 1][y]) {
            solve(x - 1, y, pos + 1, 'U');
        }
        if (x < n - 1 && !vis[x + 1][y]) {
            solve(x + 1, y, pos + 1, 'D');
        }
        if (y > 0 && !vis[x][y - 1]) {
            solve(x, y - 1, pos + 1, 'L');
        }
        if (y < n - 1 && !vis[x][y + 1]) {
            solve(x, y + 1, pos + 1, 'R');
        }
    }
    if (s[pos] == 'U' && x > 0 && !vis[x - 1][y]) {
        solve(x - 1, y, pos + 1, 'U');
    }
    if (s[pos] == 'D' && x < n - 1 && !vis[x + 1][y]) {
        solve(x + 1, y, pos + 1, 'D');
    }
    if (s[pos] == 'L' && y > 0 && !vis[x][y - 1]) {
        solve(x, y - 1, pos + 1, 'L');
    }
    if (s[pos] == 'R' && y < n - 1 && !vis[x][y + 1]) {
        solve(x, y + 1, pos + 1, 'R');
    }
    vis[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = sqrt(s.size() + 1);
    solve(0,0,0,0);
    cout << ans << '\n';
    return 0;
}