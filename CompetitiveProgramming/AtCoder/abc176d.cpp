#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int inf = 1e9 + 7;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node{
    int u, v, dist;
    bool operator < (const Node &oth) const {
        return dist > oth.dist;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int h, w; cin >> h >> w;
    vector<int> start(2), finish(2);
    rep(i,2) {
        cin >> start[i];
        --start[i];
    }
    rep(i,2) {
        cin >> finish[i];
        --finish[i];
    }
    vector<vector<char> > a(h, vector<char>(w));
    rep(i,h) {
        rep(j,w) {
            cin >> a[i][j];
        }
    }
    function<bool(int, int)> valid = [&] (int u, int v) {
        return u >= 0 && v >= 0 && u < h && v < w && a[u][v] == '.';
    };
    vector<vector<bool> > vis(h, vector<bool>(w, 0));
    vector<vector<int> > element(h, vector<int>(w, -1));
    int elementCounter = 0;
    rep(i,h) {
        rep(j,w) {
            if (!vis[i][j] && a[i][j] == '.') {
                queue<pair<int, int> > q;
                q.push({i, j});
                vis[i][j] = 1;
                while (q.size()) {
                    int u = q.front().first;
                    int v = q.front().second;
                    q.pop();
                    element[u][v] = elementCounter;
                    rep(i,4) {
                        int newu = u + dx[i];
                        int newv = v + dy[i];
                        if (!valid(newu, newv)) continue;
                        if (!vis[newu][newv]) {
                            q.push({newu, newv});
                            vis[newu][newv] = 1;
                        }
                    }
                }
                elementCounter += 1;
            }
        }
    }
    vector<set<int> > adj(elementCounter);
    rep(i,h) rep(j,w) vis[i][j] = 0;
    rep(i,h) {
        rep(j,w) {
            if (!vis[i][j] && a[i][j] == '.') {
                queue<pair<int, int> > q;
                q.push({i, j});
                vis[i][j] = 1;
                while (sz(q)) {
                    int u = q.front().first;
                    int v = q.front().second;
                    q.pop();
                    fore(ii,-2,2) {
                        fore(jj,-2,2) {
                            int newu = u + ii;
                            int newv = v + jj;
                            if (!valid(newu, newv)) continue;
                            if (element[newu][newv] == element[u][v] && !vis[newu][newv]) {
                                vis[newu][newv] = 1;
                                q.push({newu, newv});
                            }
                            if (element[newu][newv] != element[u][v]) {
                                adj[element[newu][newv]].insert(element[u][v]);
                                adj[element[u][v]].insert(element[newu][newv]);
                            }
                        }
                    }
                }
            }
        }
    }
    vector<int> dist(elementCounter, inf);
    queue<int> q;
    q.push(element[start[0]][start[1]]);
    dist[element[start[0]][start[1]]] = 0;
    while (sz(q)) {
        int u = q.front();
        q.pop();
        for(int v: adj[u]) {
            if (mini(dist[v], dist[u] + 1)) {
                q.push(v);
            }
        }
    }
    if (dist[element[finish[0]][finish[1]]] >= inf) dist[element[finish[0]][finish[1]]] = -1;
    cout << dist[element[finish[0]][finish[1]]];
    return 0;
}