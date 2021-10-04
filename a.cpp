#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    rep(i,n) {
        rep(j,m) {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> comp(n, vector<int>(m, -1));
    int cnt_comp = 0;
    rep(i,n) {
        rep(j,m) {
            if (a[i][j] == '.' && comp[i][j] == -1) {
                queue<pair<int, int>> q;
                q.push({i, j});
                comp[i][j] = ++cnt_comp;
                while (q.size()) {
                    int u = q.front().first;
                    int v = q.front().second;
                    q.pop();
                    rep(k,4) {
                        int newu = u + dx[k];
                        int newv = v + dy[k];
                        if (newu < 0 || newu >= n || newv < 0 || newv >= m) continue;
                        if (a[newu][newv] == '*') continue;
                        if (comp[newu][newv] == -1) {
                            comp[newu][newv] = comp[i][j];
                            q.push({newu, newv});
                        }
                    }
                }
            }
        }
    }
    vector<int> size_comp(cnt_comp, 0);
    rep(i,n) {
        rep(j,m) {
            if (comp[i][j] == -1) continue;
            size_comp[comp[i][j]] += 1;
        }
    }
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<bool>> vis2(n, vector<bool>(m, 0));
    int ans = 0;
    vector<vector<char>> b(n, vector<char>(m));
    rep(i,n) {
        rep(j,m) {
            b[i][j] = a[i][j];
        }
    }
    rep(i,n) {
        rep(j,m) {
            if (a[i][j] == '*' || vis[i][j]) continue;
            int cnt = 0;
            queue<pair<pair<int, int>, int>> q;
            q.push({{i, j}, 1});
            vis[i][j] = 1;
            while (q.size()) {
                int u = q.front().first.first;
                int v = q.front().first.second;
                int state = q.front().second;
                q.pop();
                cnt += state;
                rep(k,4) {
                    int newu = u + dx[k];
                    int newv = v + dy[k];
                    if (newu < 0 || newu >= n || newv < 0 || newv >= m) continue;
                    if (a[newu][newv] == '*' || vis[newu][newv]) continue;
                    vis[newu][newv] = 1;
                    q.push({{newu, newv}, 1 - state});
                }
            }
            if (cnt > size_comp[comp[i][j]] - cnt) {
                q.push({{i, j}, 1});
                ans += cnt;
            } else {
                q.push({{i, j}, 0});
                ans += size_comp[comp[i][j]] - cnt;
            }
            vis2[i][j] = 1;
            while (q.size()) {
                int u = q.front().first.first;
                int v = q.front().first.second;
                int state = q.front().second;
                if (state) b[u][v] = 'C';
                q.pop();
                rep(k,4) {
                    int newu = u + dx[k];
                    int newv = v + dy[k];
                    if (newu < 0 || newu >= n || newv < 0 || newv >= m) continue;
                    if (a[newu][newv] == '*' || vis2[newu][newv]) continue;
                    vis2[newu][newv] = 1;
                    q.push({{newu, newv}, 1 - state});
                }
            }
        }
    }
    cout << ans << '\n';
    rep(i,n) {
        rep(j,m) {
            cout << b[i][j];
        }
        cout << '\n';
    }
    return 0;
}