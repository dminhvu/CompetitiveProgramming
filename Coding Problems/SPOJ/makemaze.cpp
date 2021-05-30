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
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n, m; cin >> n >> m;
        vector<vector<char> > mat(n, vector<char>(m));
        rep(i,n) {
            rep(j,m) {
                cin >> mat[i][j];
            }
        }
        // check if there exist exactly 2 exits
        int count_exit = 0;
        int sx = -1, sy = -1;
        int tx = -1, ty = -1;
        rep(i,n) {
            rep(j,m) {
                if (mat[i][j] != '.') continue;
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (sx == -1 && sy == -1) {
                        sx = i, sy = j;
                    } else if (tx == -1 && ty == -1) {
                        tx = i, ty = j;
                    }
                    count_exit += 1;
                }
            }
        }
        if (count_exit != 2) {
            cout << "invalid\n";
            continue;
        }

        // bfs to check whether there is a path from (sx,sy) to (tx,ty)
        queue<pair<int, int> > q;
        q.push({sx, sy});
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        vis[sx][sy] = true;
        while (q.size()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            if (u > 0 && mat[u - 1][v] == '.' && !vis[u - 1][v]) {
                vis[u - 1][v] = true;
                q.push({u - 1, v});
            }
            if (u < n - 1 && mat[u + 1][v] == '.' && !vis[u + 1][v]) {
                vis[u + 1][v] = true;
                q.push({u + 1, v});
            }
            if (v > 0 && mat[u][v - 1] == '.' && !vis[u][v - 1]) {
                vis[u][v - 1] = true;
                q.push({u, v - 1});
            }
            if (v < m - 1 && mat[u][v + 1] == '.' && !vis[u][v + 1]) {
                vis[u][v + 1] = true;
                q.push({u, v + 1});
            }
        }
        cout << (vis[tx][ty] ? "valid\n" : "invalid\n");
    }
    return 0;
}