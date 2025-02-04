#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

vector<int> adj[N];
int h[N], sz[N], det[N];

int dfs(int u, int pa = 0){
    h[u] = h[pa] + 1;
    sz[u] = 1;
    for(int v: adj[u]){
        if (v==pa) continue;
        sz[u] += dfs(v, u);
    }
    det[u] = sz[u] - h[u];
    return sz[u];
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    sort(det+1,det+n+1,greater<int>());
    int64_t res = 0;
    for(int i=1; i<=n-k; i++) res += det[i];
    cout << res;
    return 0;
}