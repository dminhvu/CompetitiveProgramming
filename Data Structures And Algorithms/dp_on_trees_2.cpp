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
    int ans = 0;
    vector<int> f(n, 0), g(n, 0);
    function<void(int,int)> dfs = [&] (int u, int p) {
        int max1 = -1, max2 = -1;
        for (int v: adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            if (f[v] >= max1) {
                if (f[v] > max1) {
                    max2 = max1;
                    max1 = f[v];
                } else {
                    max2 = f[v];
                }
            } else if (f[v] > max2) {
                max2 = f[v];
            }
        }
        if (max1 != -1) f[u] = 1 + max1;
        g[u] = 0;
        if (max1 != -1 && max2 != -1) g[u] = 2 + max1 + max2;
        ans = max(ans, max(f[u], g[u]));
    };
    dfs(0,-1);
    cout << ans;
    return 0;
}