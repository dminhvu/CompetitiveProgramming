#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

set<int> s[N], unvis;
int n, m;
int sz;
bool vis[N];

void bfs(int u){
    queue<int> q;
    q.push(u);
    while (q.size()){
        int u = q.front();
        ++sz;
        q.pop();
        vector<int> tmp;
        for (int v: unvis){
            if (!s[u].count(v)){
                q.push(v);
                tmp.push_back(v);
            }
        }
        for (int x: tmp) unvis.erase(x);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // freopen("input.txt","r",stdin);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        s[u].insert(v);
        s[v].insert(u);
    }
    memset(vis,0,sizeof vis);
    vector<int> ans;
    for(int i=1; i<=n; i++) unvis.insert(i);
    for(int i=1; i<=n; i++){
        if (unvis.count(i)){
            unvis.erase(i);
            sz = 0;
            bfs(i);
            ans.push_back(sz);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int x: ans) cout << x << " ";
    return 0;
}