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
const ll inf = 1e18;

struct Node{
    int v; ll w;
    bool operator < (const Node &oth) const {
        return w > oth.w;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<Node> > adj(n);
    rep(i,m) {
        int u, v; cin >> u >> v;
        --u; --v;
        ll w; cin >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    priority_queue<Node> pq;
    vector<ll> dist(n, inf), distw(n, inf);
    // vector<int> cnt(n, 0);
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size()) {
        int u = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if (w != dist[u]) continue;
        for(Node p: adj[u]) {
            int v = p.v;
            ll d = p.w;
            if (mini(dist[v], dist[u] + d)) {
                pq.push({v, dist[v]});
            }
        }
    }
    if (dist[n - 1] >= inf) {
        rep(i,n) cout << "none\n";
        return 0;
    }
    distw[n - 1] = 0;
    // cnt[n - 1] = 1;
    pq.push({n - 1, 0});
    while (pq.size()) {
        int u = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if (w != distw[u]) continue;
        for(Node p: adj[u]) {
            int v = p.v;
            ll d = p.w;
            if (mini(distw[v], distw[u] + d)) {
                // cnt[v] = cnt[u];
                pq.push({v, distw[v]});
            } else if (distw[v] == distw[u] + d) {
                // cnt[v] += cnt[u];
            }
        }
    }
    vector<bool> f(n, 0), cutV(n, 0);
    rep(i,n) {
        if (dist[i] + distw[i] == dist[n - 1]) {
            f[i] = 1;
        }
    }
    int Time = 0;
    vector<int> Low(n, 0), Num(n, 0);

    function<void(int,int)> dfs = [&] (int u, int pa) {
        Low[u] = Num[u] = ++Time;
        int children = 0;
        bool tmp = 0;
        for(Node p: adj[u]) {
            int v = p.v;
            if (!f[v]) continue;
            if (v == pa) continue;
            if (!Num[v]) {
                children++;
                dfs(v, u);
                if (Low[v] >= Num[u]) tmp = 1;
                mini(Low[u], Low[v]);
            } else {
                mini(Low[u], Num[v]);
            }
        }
        if (pa == -1) {
            if (children > 1) cutV[u] = 1;
        } else {
            if (tmp) cutV[u] = 1;
        }
    };
    rep(i,n) if (!Num[i] && f[i]) dfs(i, -1);
    cutV[0] = cutV[n - 1] = 1;
    rep(i,n) {
        if (f[i]) {
            if (cutV[i]) cout << "all\n";
            else cout << "some\n";
        } else {
            cout << "none\n";
        }
    }
    return 0;
}

/*
8 9
1 2 1
1 3 1
2 4 1
3 4 1
4 5 1
5 6 2
5 7 1
6 8 1
7 8 1
*/