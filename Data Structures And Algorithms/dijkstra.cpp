/*
Task: Dijkstra algorithm in O(n^2 + m)
*/

#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int N = 1e5 + 5;
const int inf = 1e9;

int dist[N];
int n, m;
vector<pair<int, int> > adj[N];

void Dijkstra() {
    queue<int> q;
    dist[1] = 0;
    for (int i = 2; i <= n; i++) dist[i] = inf;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << 1 << " -> " << i << " = " << dist[i] << "\n";
    }
}

int main() {
    freopen("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i,m) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijkstra();
    return 0;
}