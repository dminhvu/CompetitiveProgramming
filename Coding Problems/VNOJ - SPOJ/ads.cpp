#include<bits/stdc++.h>

using namespace std;
const int N = 2e3 + 5;

int n, m;
vector<int> adj[N];
int Low[N], Num[N];
int cnt = 0, ans = 0;

void dfs(int u, int p = -1){
    Low[u] = Num[u] = ++cnt;
    for(int v: adj[u]){
        if (Num[v]){
            if (Num[u]<Num[v]) ans++;
        }
        else{
            dfs(v, u);
        }
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        if (!Num[i]) dfs(i);
    }
    cout << ans << '\n';
    return 0;
}