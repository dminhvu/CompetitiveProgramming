#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        vector<vector<int> > adj(n);
        for(int i=0; i<m; i++){
            int u, v; cin >> u >> v;
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> col(n, -1);
        vector<bool> vis(n, 0);
        queue<int> q; q.push(0);
        vis[0] = 1;
        while(q.size()){
            int u = q.front(); q.pop();
            if (col[u]==-1){
                col[u] = 0;
                for(int v: adj[u]) col[v] = 1;
            }
            for(int v: adj[u]){
                if (!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        vector<int> ans;
        bool f = 1;
        for(int i=0; i<n; i++){
            if (col[i]==-1){
                f = 0;
                break;
            }
            else if (col[i]==0) ans.push_back(i);
        }
        if (!f) cout << "NO\n";
        else{
            cout << "YES\n";
            cout << ans.size() << '\n';
            for (int x: ans) cout << x + 1 << " ";
            cout << '\n';
        }
    }
    return 0;
}