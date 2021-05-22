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
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int> > adj(n);
        rep(i,m) {
            int u, v; cin >> u >> v;
            --u; --v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<bool> vis(n, 0);
        function<int(int,int)> dfs = [&] (int u, int p) {
            int cnt = 1;
            vis[u] = 1;
            for(int v: adj[u]) {
                if (v == p) continue;
                if (vis[v]) continue;
                cnt += dfs(v, u);
            }
            return cnt;
        };
        vector<int> ans;
        rep(i,n) {
            if (!vis[i]) {
                ans.pb(dfs(i,-1));
            }
        }
        ll res = 0;
        rep(i,sz(ans)) {
            rep(j,sz(ans)) {
                if (j <= i) continue;
                res += 2ll * ans[i] * ans[j];
            }
        }
        cout << res << '\n';
    }
    return 0;
}