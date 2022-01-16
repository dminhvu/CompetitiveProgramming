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
    int n, m; cin >> n >> m;
    vector<vector<char> > a(n, vector<char>(m));
    int sx, sy;
    int tx, ty;
    rep(i,n) {
        rep(j,m) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                sx = i, sy = j;
            }
            if (a[i][j] == 'B') {
                tx = i, ty = j;
            }
        }
    }
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    vector<vector<int> > prev(n, vector<int>(m, -1));
    queue<tuple<int, int> > q;
    vis[sx][sy] = true;
    q.push({sx, sy});
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    while (q.size()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        q.pop();
        
        rep(i,4) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < m && a[newx][newy] != '#' && !vis[newx][newy]) {
                vis[newx][newy] = true;
                prev[newx][newy] = i;
                q.push({newx, newy});
            }
        }
    }
    
    char dir[4] = {'U', 'L', 'D', 'R'};
    if (!vis[tx][ty]) {
        cout << "NO";
    } else {
        vector<int> ans;
        while (tx != sx || ty != sy) {
            int p = prev[tx][ty];
            ans.push_back(p);
            tx -= dx[p];
            ty -= dy[p];
        }
        reverse(ans.begin(),ans.end());
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (int x: ans) cout << dir[x];
    }
    return 0;
}