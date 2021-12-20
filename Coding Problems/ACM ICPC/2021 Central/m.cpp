#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int> > adj(n);
    rep(i,m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> count;
    vector<bool> vis(n, false);
    rep(i,n) {
        if (vis[i]) continue;
        queue<int> q;
        q.push(i);
        vis[i] = true;
        count.push_back(0);
        while (q.size()) {
            count[count.size() - 1] += 1;
            int u = q.front();
            q.pop();
            for(int v: adj[u]) {
                if (vis[v]) continue;
                q.push(v);
                vis[v] = true;
            }
        }
    }
    ll ans = 0;
    vector<ll> fact(n + 1, 1ll);
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] % MOD * i % MOD) % MOD;
    }
    for (int i = 0; i < count.size(); i++) {
        if (count[i] > 2) {
            ans = (ans % MOD + fact[count[i]] % MOD) % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}