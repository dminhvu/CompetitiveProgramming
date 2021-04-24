#include<bits/stdc++.h>

using namespace std;
const int64_t inf = 1e18;
const int N = 2e5 + 5;

struct Dijk{
    int u;
    int64_t w, maxw, minw, val;
    bool operator < (const Dijk &oth) const{
        return val>oth.val;
    }
};

struct mst{
    int u, v, w;
    bool operator < (const mst &oth) const{
        return w<oth.w;
    }
};

int64_t dist[N];
int pa[N];

int root(int x){
    return pa[x]==x ? x : pa[x] = root(pa[x]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<pair<int, int> > > adj(n + 1);
    vector<mst> e;
    for(int i=0; i<k; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<Dijk> pq;
    pq.push({1, 0ll, -inf, inf, 0ll});
    for(int i=1; i<=n; i++) dist[i] = inf;
    dist[1] = 0;
    while (pq.size()){
        Dijk cur = pq.top(); pq.pop();
        int u = cur.u;
        //cout << cur.u << " ";
        for(int i=0; i<adj[cur.u].size(); i++){
            int v = adj[cur.u][i].first;
            int64_t w = 1ll * adj[cur.u][i].second;
            if (dist[v] >= dist[cur.u] + w + (cur.maxw==-inf?0:cur.maxw) - (cur.minw==inf?0:cur.minw) - max(w, cur.maxw) + min(w, cur.minw)){
                dist[v] = dist[cur.u] + w + (cur.maxw==-inf?0:cur.maxw) - (cur.minw==inf?0:cur.minw) - max(w, cur.maxw) + min(w, cur.minw);
                pq.push({v, cur.w + w, max(w, cur.maxw), min(w, cur.minw), dist[v]});
            }
        }
    }
    for(int i=2; i<=n; i++) cout << dist[i] << " ";
    return 0;
}