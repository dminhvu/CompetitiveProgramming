#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

struct myData{
    int u, v, k;
};

vector<int> adj[N];
vector<myData> ans;
bool vis[N];
int p[N];

void dfs(int u, int pa = -1){
    vis[u] = 1;
    for(int v: adj[u]){
        if (v==pa) continue;
        if (vis[v]){
            if (v==p[p[u]]){
                ans.push_back({v, u, p[u]});
            }
            continue;
        }
        p[v] = u;
        dfs(v, u);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i=0; i<n; i++){
    //     if (!vis[i]){
    //         vis[i] = 1;
    //         dfs(i);
    //     }
    // }
    memset(vis,0,sizeof vis);
    for(int i=0; i<n; i++){
        if (!vis[i]){
            vis[i] = 1;
            dfs(i);
        }
    }
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++){
        cout << ans[i].u + 1 << " " << ans[i].v + 1 << " " << ans[i].k + 1 << '\n';
    }
    return 0;
}