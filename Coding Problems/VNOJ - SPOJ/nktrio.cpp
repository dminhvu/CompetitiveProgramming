#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;

struct myData{
    int x, y, z;
};

int n;
vector<int> adj[N];
vector<myData> ans;
int h[N];
bool vis[N];

void dfs(int u, int pa = -1){
    if (!ans.empty()) return;
    for(int v: adj[u]){
        if (v==pa) continue;
        if (vis[v]){
            if (h[u] - h[v] == 2){
                ans.push_back({u, v, pa});
            }
        }
        else{
            h[v] = h[u] + 1;
            vis[v] = 1;
            dfs(v, u);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x; cin >> x;
            if (x) adj[i].push_back(j);
        }
    }
    memset(vis,0,sizeof vis);
    memset(h,0,sizeof h);
    for(int i=1; i<=n; i++){
        if (!vis[i]){
            vis[i] = 1;
            dfs(i);
        }
        if (!ans.empty()) break;
    }
    if (ans.empty()) cout << "-1 -1 -1\n";
    else cout << ans[0].x << " " << ans[0].y << " " << ans[0].z << '\n';
    return 0;
}