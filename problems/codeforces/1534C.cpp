#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define fore(i,a,b) for (int i = int(a); i <= int(b); i++)
#define ford(i,a,b) for (int i = int(a); i >= int(b); i--)
#define ll int64_t
#define sz(x) int(x.size())

using namespace std;
template<class t, class u> bool maxi(t &a, u b){ if (a < b){ a = b; return 1;} return 0;}
template<class t, class u> bool mini(t &a, u b){ if (a > b){ a = b; return 1;} return 0;}
const int mod = 1e9 + 7;

int main() {
    // freopen64("input.txt","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int nTest; cin >> nTest;
    while (nTest--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        rep(i,n) {
            cin >> a[i];
            --a[i];
        }
        rep(i,n) {
            cin >> b[i];
            --b[i];
        }
        rep(i,n) {
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }
        function<void(int)> dfs = [&] (int u) {
            vis[u] = 1;
            for(int v: adj[u]) {
                if (vis[v]) continue;
                dfs(v);
            }
        };
        int ans = 1;
        rep(i,n) {
            if (vis[i]) continue;
            dfs(i);
            ans *= 2;
            ans %= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}