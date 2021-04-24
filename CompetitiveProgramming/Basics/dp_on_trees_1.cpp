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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("input.txt","r",stdin);
    int n; cin >> n;
    vector<vector<int> > adj(n);
    rep(i,n-1) {
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    vector<vector<int> > dp(2); 
    dp[0].resize(n,0);
    dp[1].resize(n,0);
    function<void(int,int)> dfs = [&] (int u, int p) {
        for(int v: adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            dp[0][u] += dp[1][v];
            dp[1][u] += max(dp[0][v], dp[1][v]);
        }
        dp[0][u] += c[u];
    };
    dfs(0,-1);
    cout << max(dp[0][0], dp[1][0]);
    return 0;
}