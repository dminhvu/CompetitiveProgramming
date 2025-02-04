#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > mat(n, vector<int>(m));
    rep(i,n) {
        rep(j,m) {
            cin >> mat[i][j];
        }
    }
    vector<int> room_sizes;
    vector<vector<int> > color(n, vector<int>(m, 0));
    int count_color = 0;
    rep(i,n) {
        rep(j,m) {
            if (!color[i][j]) {
                queue<pair<int, int> > q;
                q.push({i, j});
                color[i][j] = ++count_color;
                int room_size = 0;
                while (q.size()) {
                    int u = q.front().first;
                    int v = q.front().second;
                    q.pop();
                    room_size += 1;
                    int val = mat[u][v];
                    rep(k,4) {
                        if (!((val >> k) & 1)) {
                            int newu = u + dx[k];
                            int newv = v + dy[k];
                            if (newu < 0 || newv < 0 || newu >= n || newv >= m) continue;
                            if (!color[newu][newv]) {
                                q.push({newu, newv});
                                color[newu][newv] = count_color;
                            }
                        }
                    }
                }
                room_sizes.push_back(room_size);
            }
        }
    }
    sort(room_sizes.begin(), room_sizes.end(), greater<int>());
    for (int x: room_sizes) cout << x << " ";
    return 0;
}