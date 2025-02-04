#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

string s[N];
vector<int> adj[N];

void dfs(int u){
    vis[u] = 1;
    cout << ans[u] << " ";
    for(int v: adj[u]){
        if (vis[v]) continue;
        dfs(v);
    }
}

void check(int x, int y){
    string t1 = s[x];
    string t2 = s[y];
    
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> s[i];
    for(int i=0; i<n; i++){
        if (i==j) continue;
        for(int j=0; j<n; j++){
            check(i, j);
            check(j, i);
        }
    }
    return 0;
}