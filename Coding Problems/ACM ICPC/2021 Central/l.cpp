#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int inf = 1e9;

int bfs(vector<vector<int> > adj, int x, int y) {
    queue<int> q;
    vector<int> dist(adj.size(), inf);
    vector<bool> vis(adj.size(), false);
    q.push(x);
    dist[x] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v: adj[u]) {
            if (vis[v]) {
                continue;
            }
            if (v == y) return dist[v];
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<vector<int> > adj(n);
    rep(i,n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int p = 0;
    while (q--) {
        int u, v; cin >> u >> v;
        u = (u + p) % n;
        v = (v + p) % n;
        int ans = bfs(adj, u, v);
        cout << ans << '\n';
        p = ans;
    }
    return 0;
}