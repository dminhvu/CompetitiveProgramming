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
        vector<vector<char>> a(n, vector<char>(m));
        rep(i,n) rep(j,m) cin >> a[i][j];
        queue<pair<pair<int, int>, int> > q;
        rep(i,n) rep(j,m) {
            if (a[i][j] == '.') continue;
            q.push({{i, j}, a[i][j] == 'R'});
        }
        if (q.empty()) {
            a[0][0] = 'R';
            q.push({{0, 0}, 1});
        }
        while (q.size()) {
            int u = q.front().first.first;
            int v = q.front().first.second;
            int c = q.front().second;
            q.pop();
            if (u > 0 && a[u - 1][v] == '.') {
                q.push({{u - 1, v}, 1 - c});
                a[u - 1][v] = (c == 0 ? 'R' : 'W');
            }
            if (v > 0 && a[u][v - 1] == '.') {
                q.push({{u, v - 1}, 1 - c});
                a[u][v - 1] = (c == 0 ? 'R' : 'W');
            }
            if (u < n - 1 && a[u + 1][v] == '.') {
                q.push({{u + 1, v}, 1 - c});
                a[u + 1][v] = (c == 0 ? 'R' : 'W');
            }
            if (v < m - 1 && a[u][v + 1] == '.') {
                q.push({{u, v + 1}, 1 - c});
                a[u][v + 1] = (c == 0 ? 'R' : 'W');
            }
        }
        bool f = 1;        
        int sr = -1, sw = -1;
        rep(i,n) rep(j,m) {
            if (a[i][j] == 'R') {
                if (sr == -1) {
                    sr = (i + j) % 2;
                } else if (sr != (i + j) % 2) {
                    f = 0;
                    break;
                }
            } else if (a[i][j] == 'W') {
                if (sw == -1) {
                    sw = (i + j) % 2;
                } else if (sw != (i + j) % 2) {
                    f = 0;
                    break;
                }
            }
        }
        if (!f) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        rep(i,n) {
            rep(j,m) cout << a[i][j];
            cout << '\n';
        }
    }
    return 0;
}